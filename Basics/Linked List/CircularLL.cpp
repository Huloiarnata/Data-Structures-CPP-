#include <iostream>
using namespace std;
typedef struct Node{
    int val;
    Node *next;
};
Node *NewNode(Node *head){
    Node *ptr = head;
    do{
        ptr=ptr->next;
    }while(ptr!=head);
    Node *tmp = (Node *)malloc(sizeof(Node));
    cout<<"Enter entry: ";int value; cin>>value;
    tmp->val=value;
    tmp->next=head;
    ptr->next=tmp;
    return head;
}
void showData(Node *head){
    Node *ptr = head;
    do{
        cout<<"->"<<ptr->val;
        ptr=ptr->next;
    }while(ptr!=head);
}
int main(void){
    cout<<"Enter num of entry: ";
    int n;cin>>n;
    Node *head = (Node *)malloc(sizeof(Node));
    cout<<"Enter entry: ";
    int headData;cin>>headData;
    head->val=headData;
    head->next=head;
    while(n>1){
        head = NewNode(head);
        n--;
    }
    showData(head);
    return 0;
}