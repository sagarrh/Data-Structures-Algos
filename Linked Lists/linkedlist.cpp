#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* CreateNode(int value){
    Node *newnode=new Node();
    newnode->data=value;
    newnode->next=nullptr;
    return newnode;
}

void append(Node *& head,int value){
    Node *newnode= CreateNode(value);
    if(!head){
        head=newnode;
    }
    else{
        Node *temp =head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void printList(Node *head){
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node *a=nullptr;
    append(a,12);
    append(a,43);
    append(a,87);
    printList(a);
}