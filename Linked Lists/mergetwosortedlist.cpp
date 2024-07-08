#include<iostream>

using namespace std;
struct ListNode{
    int data;
    ListNode *next;
};

//merging two sorted linked list;

ListNode* mergetwosortedlinkedlist(ListNode *list1,ListNode *list2){
    ListNode *dummynode=new ListNode();
       ListNode *temp=dummynode;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->data>=list2->data){
                temp->next=list2;
                list2=list2->next;
            }else{
               temp->next=list1;
               list1=list1->next;
            }
            temp=temp->next;
        }
        if(list1!=nullptr){
            temp->next=list1;
        }
        if(list2!=nullptr){
            temp->next=list2;
        }
        return dummynode->next;  
}

void printList(ListNode *node){
    while(node!=nullptr){
        cout<<node->data<<"->";
        node=node->next;
    }
    cout<<endl;
}

int main(){
    ListNode *list1 = new ListNode();
    list1->data = 1;
    list1->next = new ListNode();
    list1->next->data = 3;
    list1->next->next = new ListNode();
    list1->next->next->data = 5;
    list1->next->next->next = nullptr;

    ListNode *list2 = new ListNode();
    list2->data = 2;
    list2->next = new ListNode();
    list2->next->data = 4;
    list2->next->next = nullptr;

    ListNode *mergedList = mergetwosortedlinkedlist(list1, list2);
    cout << "Merged List: ";
    printList(mergedList);


    return 0;

}