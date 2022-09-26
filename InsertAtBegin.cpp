#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node(int val){
        data=val;
        next=NULL;
    }
};

node*head=NULL;
void InsertAtHead(int val){
    node*n=new node(val);
    node*temp=head;
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
void InsertAtTail(int val){
    node*n=new node(val);
    node*temp=head;
    if(head==NULL){
        InsertAtHead(val);
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void Display(){
    node*temp=head;
   do
   {
    cout<<temp->data<<" ";
    temp=temp->next;
   } while (temp!=head);
   
    cout<<endl;
}

int main()
{
    InsertAtTail(3);
    InsertAtTail(2);
    InsertAtTail(6);
    InsertAtTail(9);
    InsertAtTail(5);
    Display();
    InsertAtHead(44);
    Display();

    return 0;
}