#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
    
    // Push the head of each list into the priority queue
    for (auto list : lists) {
        if (list != nullptr) {
            pq.push(make_pair(list->val, list));
        }
    }

    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;

    while (!pq.empty()) {
        pair<int,ListNode*> top = pq.top(); // Extract the node with the smallest value
        pq.pop();
        int val= top.first;
        ListNode* node = top.second;
        temp->next=node;
        temp=temp->next;
        if(node->next!=nullptr){
            pq.push(make_pair(node->next->val,node->next));
        }
    }

    return dummy->next;
}

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

    // Free memory
    ListNode* current = mergedList;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
