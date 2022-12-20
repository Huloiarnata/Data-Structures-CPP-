#include<iostream>
using namespace std;
struct Node{
    struct Node* prev;
    int value;
    struct Node* next;

};
struct Node *NewNode(struct Node *head){
    struct Node *ptr = head;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    struct Node *tmp = (struct Node *)malloc(sizeof(Node));
    cout<<"Enter entry: ";
    int entryData;cin>>entryData;
    tmp->value=entryData;
    tmp->next=NULL;
    tmp->prev=ptr;
    ptr->next = tmp;
    return head;
}
void showData(struct Node* head){
    struct Node* ptr = head;
    cout<<"List of Entry: ";
    while(ptr!=NULL){
        cout<<">>"<<ptr->value;
        ptr=ptr->next;
    }
    cout<<endl;
}
void reverseData(struct Node* head){
    struct Node* ptr= head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    while(ptr!=NULL){
        cout<<"<<"<<ptr->value;
        ptr=ptr->prev;
    }
}
int main(void){
    cout<<"Enter num of entries:";
    int n;cin>>n;
    struct Node * head = (struct Node *)malloc(sizeof(Node));
    cout<<"Enter entry: ";
    int headData;cin>>headData;
    head->prev=head->next=NULL;
    head->value=headData;
    while(n>1){
        head = NewNode(head);
        n--;
    }
    showData(head);
    reverseData(head);

    return 0;
}