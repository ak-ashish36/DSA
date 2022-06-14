//https://takeuforward.org/data-structure/implement-lru-cache/
#include<bits/stdc++.h>
using namespace std;
struct node {
  int key;
  int val;
  node * next;
  node * prev;
  node(int key, int val) {
    this->key = key;
    this->val = val;
  }
};
class List{  
  public:
    node * head;
    node * tail;
    List(){
      head = new node(-1, -1);
      tail = new node(-1, -1);
      head -> next = tail;
      tail -> prev = head;
    }
    void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  } 
};
class LRUCache {
  public:
  unordered_map <int,node*> m;
  List list;
  int cap;
  
  LRUCache(int capacity) {
    cap = capacity;
  }

  int get(int key) {
    if (m.find(key) != m.end()) {
      node * resnode = m[key];
      int res = resnode -> val;
      m.erase(key);
      list.deletenode(resnode);
      list.addnode(resnode);
      m[key] = list.head -> next;
      return res;
    }
    return -1;
  }

  void put(int key, int value) {
    if (m.find(key) != m.end()) {
      node * existingnode = m[key];
      m.erase(key);
      list.deletenode(existingnode);
    }

    if (m.size() == cap) {
      m.erase(list.tail -> prev -> key);
      list.deletenode(list.tail -> prev);
    }

    list.addnode(new node(key, value));
    m[key] = list.head -> next;
  }
};
int main(){
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout<<lRUCache.get(1)<<endl;    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout<<lRUCache.get(2)<<endl;    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
    return 0;
}