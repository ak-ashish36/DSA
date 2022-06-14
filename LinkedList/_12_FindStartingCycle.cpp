//https://leetcode.com/problems/linked-list-cycle-ii/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print(ListNode*head){
        ListNode *temp=head;
        while (temp != NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<endl;
}
void insertAtBack(ListNode*&head,int val) {
    ListNode*newNode = new ListNode(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    ListNode*temp = head;
    while(temp->next != NULL){ temp = temp->next;}
    temp->next = newNode;
    return;
}
void createCycle(ListNode* &head,int a,int b) {
    int cnta = 0,cntb = 0;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while(cnta != a || cntb != b) {
        if(cnta != a) p1 = p1->next, ++cnta;
        if(cntb != b) p2 = p2->next, ++cntb;
    }
    p2->next = p1;
}
//Time Complexity: O(N)   Space Complexity: O(N)
ListNode* detectCycle(ListNode* head) {
    unordered_set<ListNode*> hashTable;
    while(head != NULL) {
        if(hashTable.find(head) != hashTable.end()) return head;
        hashTable.insert(head);
        head = head->next;
    }
    return NULL;
}
//Time Complexity: O(N)   Space Complexity: O(1)
ListNode* detectCycle2(ListNode* head) {
    if(head == NULL) return NULL;
    ListNode* fast = head;
    ListNode* slow = head;
        
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return slow->next;
    }
    return NULL;
}
int main(){
    ListNode *head=NULL;
    insertAtBack(head,3);
    insertAtBack(head,2);
    insertAtBack(head,0);
    insertAtBack(head,-4);

    createCycle(head,1,3);

    if(detectCycle2(head))
    cout<<"Cycle detected\n";
    else
    cout<<"Cycle not detected\n";

    ListNode* nodeRecieve = detectCycle2(head);
    if(nodeRecieve == NULL) cout<<"No cycle";
    else {
        ListNode* temp = head;
        int pos = 0;
        while(temp!=nodeRecieve) {
            ++pos;
            temp = temp->next;
        }
        cout<<"Tail connects at pos "<<pos<<endl;
    }
   
    return 0;
}