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

void InsertAtTail(int val){
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
}
void DeleteAtHead(){
    node*toDelete=head;
    node*temp=head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    
    temp->next=head->next;
    head=head->next;
    delete toDelete;
    
}
void DeleteAtEnd(){
    node*temp=head;
    while (temp->next->next!=head)
    {
        temp=temp->next;
    }
    node *toDelete=temp->next;
    temp->next=head;
    delete toDelete;
    
}
void DeleteAtAny(int pos){
    node*temp=head;
    if(pos==1){
        DeleteAtHead();

    }
    while(pos>2){      //Delete at any position 
        temp=temp->next;
        pos--;
    }
    node*toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;

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
    InsertAtTail(30);
    InsertAtTail(31);
    InsertAtTail(34);
    InsertAtTail(12);
    InsertAtTail(11);
    Display();
    DeleteAtEnd();
    Display();

    return 0;
}