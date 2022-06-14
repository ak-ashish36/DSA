#include<bits/stdc++.h>
using namespace std;
struct node {
  int key,val,cnt;
  node * next;
  node * prev;
  node(int key, int val) {
    this->key = key;
    this->val = val;
    cnt = 1; 
  }
};
class List{  
  public:
    node * head;
    node * tail;
    int size;
    List(){
      head = new node(0, 0);
      tail = new node(0, 0);
      head -> next = tail;
      tail -> prev = head;
      size=0;
    }
    void addFront(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
    size++;
    }

   void removeNode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
    size--;
    } 
};
class LFUCache {
    map<int,node*> keyNode; 
    map<int,List*> freqListMap; 
    int maxSizeCache;
    int minFreq; 
    int curSize; 
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity; 
        minFreq = 0;
        curSize = 0; 
    }
    void updateFreqListMap(node *n_node) {
        keyNode.erase(n_node->key); 
        freqListMap[n_node->cnt]->removeNode(n_node); 
        if(n_node->cnt == minFreq && freqListMap[n_node->cnt]->size == 0) {
            minFreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqListMap.find(n_node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[n_node->cnt + 1];
        } 
        n_node->cnt += 1; 
        nextHigherFreqList->addFront(n_node); 
        freqListMap[n_node->cnt] = nextHigherFreqList; 
        keyNode[n_node->key] = n_node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            node* res_node = keyNode[key]; 
            int val = res_node->val; 
            updateFreqListMap(res_node); 
            return val; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (maxSizeCache == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()) {
            node* existing_node = keyNode[key]; 
            existing_node->val = value; 
            updateFreqListMap(existing_node); 
        }
        else {
            if(curSize == maxSizeCache) {
                List* list = freqListMap[minFreq]; 
                keyNode.erase(list->tail->prev->key); 
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--; 
            }
            curSize++; 
            // new value has to be added who is not there previously 
            minFreq = 1; 
            List* listFreq = new List(); 
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq]; 
            }
            node* new_node = new node(key, value); 
            listFreq->addFront(new_node);
            keyNode[key] = new_node; 
            freqListMap[minFreq] = listFreq; 
        }
    }
};
int main(){
     LFUCache lfu(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu.get(2);      // return -1 (not found)
    lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu.get(1);      // return -1 (not found)
    lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu.get(4);      // return 4             // cache=[4,3], cnt(4)=2, cnt(3)=3
    return 0;
}