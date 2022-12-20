#include<iostream>
using namespace std;
typedef struct Node{
    int val;
    Node *next;
};
Node *NewNode(Node *head){
    Node *tmp = (Node *)malloc(sizeof(Node));
    Node *ptr = head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    cout<<"Enter entry: ";
    int value;cin>>value;
    tmp->val = value;
    tmp->next = NULL;
    ptr->next=tmp;
    return head;
}
void ShowData(Node *head){
    Node *ptr = head;
    cout<<"List of entries";
    while (ptr!=NULL)
    {
        cout<<"->"<<ptr->val;
        ptr = ptr->next;

    }
    
}
int main(void){
    cout<<"Enter Number of enteries: ";
    int n;cin>>n;
    Node *head = (Node *)malloc(sizeof(Node));
    int HeadData;
    cout<<"Enter entry: ";cin>>HeadData;
    head->val=HeadData;
    head->next=NULL;
    while(n>1){
        head = NewNode(head);
        n--;
    }
    ShowData(head);

    return 0;
}