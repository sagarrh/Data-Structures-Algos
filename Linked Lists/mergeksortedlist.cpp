#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to merge two sorted linked lists
ListNode* mergetwosortedlinkedlist(ListNode *list1, ListNode *list2) {
    ListNode *dummynode = new ListNode();
    ListNode *temp = dummynode;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val >= list2->val) {
            temp->next = list2;
            list2 = list2->next;
        } else {
            temp->next = list1;
            list1 = list1->next;
        }
        temp = temp->next;
    }

    if (list1 != nullptr) {
        temp->next = list1;
    }
    if (list2 != nullptr) {
        temp->next = list2;
    }

    return dummynode->next;
}

// Function to merge k sorted linked lists
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }

    ListNode *head = lists[0];
    for (int i = 1; i < lists.size(); ++i) {
        head = mergetwosortedlinkedlist(head, lists[i]);
    }

    return head;
}

// Utility function to print a linked list
void printList(ListNode *head) {
    ListNode *curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Test Case 1: Example with three sorted linked lists
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode *l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};

    cout << "Input Lists:" << endl;
    for (ListNode *list : lists) {
        printList(list);
    }

    ListNode *mergedList = mergeKLists(lists);

    cout << "Merged List:" << endl;
    printList(mergedList);

    
}
