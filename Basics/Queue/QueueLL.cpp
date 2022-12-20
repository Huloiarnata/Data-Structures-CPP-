#include<iostream>
using namespace std;
typedef struct Queue{
    int val;
    Queue *next;
};
Queue *front = NULL;
Queue *rear = NULL;

void EnqueueOP(int value){
    Queue *temp = (Queue *)malloc(sizeof(Queue));
    temp->val = value;
    temp->next = NULL;
    if((front == NULL)&&(rear == NULL)){
        front = rear = temp;
    }else{

        rear->next=temp;
        rear = temp;
    }
    cout<<"Succesfully Enqueued!"<<endl;
}
int DequeueOP(){
    //Check if Queue is empty or full
    if(front == NULL){
        cout<<"Queue is empty, Dequeue not possible!\n\n";
        return -1; 
    }
    else{
        int dequequed_data;
        Queue *ptr = front;
        dequequed_data = front->val;
        front = front->next;
        free(ptr);
        cout<<"Dequeued succesfully!!"<<endl;
        return dequequed_data;
    }
}
void QueueDisplayOP(){
    Queue *ptr = front;
    if((front==NULL)&&(rear==NULL)){
        cout<<"underflow!"<<endl;
    }
    else{
    do{
        cout<<ptr->val<<"->";
        ptr = ptr->next;
    }while(ptr);
    cout<<endl;
}
}

int main(void){
    while(1){
        cout<<"Choose Operation to conduct on Queue";
        cout<<endl;
        cout<<"1) Enqueue\n2) Dequeue\n3) Display\n"<<endl;
        cout<<"Enter option to choose: ";
        int choice;cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter value to enter: ";
            int value;cin>>value;
            EnqueueOP(value);
            break;
        case 2:
            printf("Dequed value is: %d\n",DequeueOP());
            break;
        case 3:
            QueueDisplayOP();
            break;
        
        default:
        cout<<"Wrong Choice!!"<<endl;
            break;
        }
    }
    

    return 0;
}