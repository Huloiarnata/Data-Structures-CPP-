#include <iostream>
using namespace std;
typedef struct StackNode{
    int val;
    StackNode *next;
};
StackNode *top = NULL;
void StackPushOP(int value){
    StackNode *temp=(StackNode*)malloc(sizeof(StackNode));;
    temp->val=value;
    if(top==NULL){
        temp->next=NULL;
    }else{
        temp->next=top;
    }
    top=temp;
}
void StackPopOP(){
    StackNode *ptr = top;
    int pop_temp_data = top->val;
    if(top == NULL){
        cout<<"Stack Underflow!\n";
    }
    else{
        top = top->next;
        free(ptr);
        cout<<"Element poped from stack succesfully: "<<pop_temp_data<<endl;

    }

}
void StackDisplayOP(){
    StackNode* ptr = top;
    while(ptr!=NULL){
        cout<<"->"<<ptr->val;
        ptr=ptr->next;
    }
    cout<<endl<<endl;
}
int main(void){
    while(1){
        cout<<endl;
        cout<<"1)Push Operation\n2)Pop Operation\n3)Display Operation"<<endl;
        cout<<"Enter Operation on stack: ";
        int choice;cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter Value to Push: ";
            int value;cin>>value;
            StackPushOP(value);
            break;
        case 2:
            StackPopOP();
            break;
        case 3:
            StackDisplayOP();
            break;
        default:
            cout<<"Wrong Option\n";
            break;
        }
    }

    return 0;
}