#include <iostream>

#include<stack>

using namespace std;
struct Node{
    int data;
    Node *next;
};

Node* createnode(int val){
    Node* NewNode = new Node();
    NewNode->data=val;
    NewNode->next=nullptr;
    return NewNode;
}
void append(Node* &head,int value){
    Node *newnode = createnode(value);
    if (!head) {
        head = newnode;
    } else {
        Node *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void printlist(Node *head){
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}

void reverselistIterative(Node* &head){
    Node *prev=nullptr;
    Node *curr=head;
    Node *next=head;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
}


Node* reverseListRecursive(Node* head) {
    if (!head || !head->next) {
        return head;
    }
    Node* rest = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}

void reverseListUsingStack(Node* &head){
    stack<Node*> s;
    Node* temp=head;
    while(temp){
        s.push(temp);
        temp=temp->next;
    }
    if(!s.empty()){
        head=s.top();
        s.pop();
    }
    temp=head;
    while(!s.empty()){
        temp->next=s.top();
        s.pop();
        temp=temp->next;
    }
    if(temp){
        temp->next=nullptr;
    }
    


}


int main(){
    Node *head= nullptr;
    append(head,12);
    append(head,14);
    append(head,16);
    append(head,18);
    append(head,90);
    printlist(head);
    Node *newhead=head;
    Node *newhead1=head;
    Node *newhead2=head;


    cout<<endl;
    reverselistIterative(newhead);
    printlist(newhead);
    cout<<endl;

    return 0;


}