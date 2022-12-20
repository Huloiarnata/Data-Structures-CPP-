#include <iostream>
using namespace std;
void InsertOP(int value,int *f,int *r,int *max,int *q){
    //If Queue is Full
    cout<<"Before Rear value: "<<*r<<endl;
    if(*r == *max-1){
        cout<<"Queue overflow!, operation not succesfull\n\n";
    }
    //If Queue is Empty
    else if((*f == -1)&&(*r == -1)){
        *f=*r=0;
        cout<<"After Rear value: "<<*r<<endl;
        q[*r]=value;
    }
    //If Queue is not full & not empty
    else{
        *r = *r + 1;
        cout<<"After Rear value: "<<*r<<endl;
        q[*r]=value;
    }
    
}
void DisplayOP(int *f,int *r,int *q){
    //Queue is empty
    if((*f==-1)||(*f>*r)){
        cout<<"Queue is Empty!\n\n";
    }
    //Queue is filled
    else{
        for(int i=*f;i<=*r;i++){
            cout<<q[i]<<"<-";
        }
    }
    cout<<endl<<endl;
}
int DeleteOP(int *f,int *r,int *q){
    int poped_element;
    //If queue is empty
    if(*f==-1 || *f>*r){
        cout<<"Queue underflow!, couldn't perform operations"<<endl;
        return -1;
    }else{
        poped_element = q[*f];
        *f = *f +1;
        if(*f>*r){
            *f=*r=-1;
        }
        return poped_element;
    }
    //If filled
}

int main(void){
    cout<<"Enter num of entry to queue: ";
    int num;cin>>num;
    int front = -1;
    int rear = -1;
    int queue[num];
    while(1){
        cout<<"Opertaion to conduct on Queue - "<<endl;
        cout<<"1) Insert\n2) Delete\n3) Display\n"<<endl;
        cout<<"Enter choice: ";
        int choice;cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value to insert: ";
                int value;cin>>value;
                InsertOP(value,&front,&rear,&num,queue);
                break;
            case 2:
                int pop_element;
                pop_element = DeleteOP(&front,&rear,queue);
                cout<<"Successfully removed: "<<pop_element<<endl;
                break;
            case 3:
                DisplayOP(&front,&rear,queue);
                break;
            default:
                break;
        }

        
    }

    return 0;
}