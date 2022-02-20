#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
class LRUCache {
    class DLL{
    public:
        int key;
        int val;
        DLL * next;
        DLL * prev;
        DLL(int k,int v):key(k),val(v),next(nullptr),prev(nullptr){};
        DLL(int k,int v,DLL* n):key(k),val(v),next(n),prev(nullptr){};
    };
    DLL * head;
    DLL * tail;
public:
    //my Own DLL class

    unordered_map<int,DLL*> hashTable;
    int capacity;

    void addToFront(int val,int key){
        head=new DLL(key,val,head);
        if(head->next){
            head->next->prev=head;
        }
        else{
            tail=head;
        }
        return;
    }
    void deleteNode (DLL * node){
        if(!node){
            return;
        }
        if(node->prev){
            node->prev->next=node->next;
        }
        else{
            head=node->next;
        }
        if(node->next){
            node->next->prev=node->prev;
        }
        else{
            tail=node->prev;
        }
        // free(node);
        return;
    }
    LRUCache(int capacity):head(nullptr),tail(nullptr),capacity(capacity){
        for(int i=0;i<capacity;++i){
            addToFront(-1,-1);
            if(i==0){
                tail=head;
            }
        }
    }
    int get(int key) {
        if(hashTable[key]==nullptr){
            return -1;
        }
        DLL * node=hashTable[key];
        deleteNode(node);
        hashTable[key]=nullptr;
        addToFront(node->val,node->key);
        hashTable[key]=head;
        return node->val;
    }
    
    void put(int key, int value){
        DLL * node=hashTable[key];
        if(hashTable[key]!=nullptr){
            deleteNode(node);
            addToFront(value,key);
            hashTable[key]=head;
            return;
        }
        hashTable[tail->key]=nullptr;
        deleteNode(tail);
        addToFront(value,key);
        hashTable[key]=head;
        return;
    }
};