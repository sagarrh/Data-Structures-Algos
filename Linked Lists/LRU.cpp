#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class LRUcache{
    public:
    //declaring doubly linked list for lru
    struct Node{
        int key,val;
        Node *next,*prev;
        Node(int key,int val):key(key),val(val),next(nullptr),prev(nullptr){};
    };

    //declaring capacity and map for mappind in constant time 
    int capacity;
    unordered_map<int,Node*> maps;
    Node *head= new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    

    LRUcache(int capacity){
        this->capacity=capacity;
        head->prev=tail;
        tail->next=head;
    }
    //for remove the node
    void remove(Node *removethis){
        removethis->next->prev=removethis->prev;
        removethis->prev->next=removethis->next;
    }
    //for adding the node 
    void add(Node *addthis){
        Node *newnode = head->prev;
        newnode->next=addthis;
        addthis->prev=newnode;
        addthis->next=head;
        head->prev=addthis;
    }

    int get(int key){
        if(maps.find(key)==maps.end()) return -1;

        Node *thisnode = maps[key];
        remove(thisnode);
        add(thisnode);
        return thisnode->val;


    }
    
    void put(int key,int val){
        //there are some conditions for this 
        // if the key and val already exists in maps then remove that key and val and replace the val with the new value;
        if(maps.find(key)!=maps.end()){
            Node *foundit = maps[key];
            remove(foundit);
            
        }
            //if not present in the maps then add the new value and new key
            Node *newnode= new Node(key,val);
            maps[key]=newnode;
            add(newnode);


            //is the map.size() is beyond what the capacity can handle remove lru;
            if(maps.size()>capacity){
                Node *removethis = tail->next;
                remove(removethis);
                maps.erase(removethis->val);
            }


    }

};
int main(){
    LRUcache cache(2); // Capacity is 2

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // Expected output: 1
    cout << cache.get(2) << endl; // Expected output: 2
    cout << cache.get(3) << endl; // Expected output: -1 (key 3 not in cache)

    cache.put(3, 3); // Evicts key 1
    cout << cache.get(1) << endl; // Expected output: -1 (key 1 evicted)
    cout << cache.get(2) << endl; // Expected output: 2
    cout << cache.get(3) << endl; // Expected output: 3

    cache.put(4, 4); // Evicts key 2
    cout << cache.get(2) << endl; // Expected output: -1 (key 2 evicted)
    cout << cache.get(3) << endl; // Expected output: 3
    cout << cache.get(4) << endl; // Expected output: 4

    return 0;

}