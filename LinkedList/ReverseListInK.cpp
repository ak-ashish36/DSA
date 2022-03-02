#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void insert(int value,ListNode**head){
        ListNode* node=new ListNode(value);
        node->next=*head;
        *head=node;
}
void print(ListNode*head){
        ListNode *temp=head;
        while (temp != NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<endl;
}
int lengthOfLinkedList(ListNode* head) {
    int length = 0;
    while(head != NULL) {
        ++length;
        head = head->next;
    }
    return length;
}
ListNode * reverseKGroup(ListNode*head,int k){
    if(head == NULL||head->next == NULL) return head;
    ListNode*curr=head;
    ListNode*prev=NULL;
    ListNode*next=head;
    int lenght=lengthOfLinkedList(head);
   if(lenght>=k){
    int count=0;
    while(curr!=NULL && count<k){
        next =curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(curr != NULL){
        head->next=reverseKGroup(curr,k);
    }
    return prev;
   }
   else{
       return head;
   }
}
ListNode * reverseKGroup2(ListNode*head,int k){
    if(head == NULL||head->next == NULL) return head;
    int length = lengthOfLinkedList(head);
    ListNode * dummy=new ListNode();
    dummy->next = head;
    ListNode*prev=dummy;
    ListNode*curr;
    ListNode*next;
     while(length >= k) {
         curr=prev->next;
         next=curr->next;
        for(int i=1;i<k;i++) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev=curr;
        length -= k;
    }
    return dummy->next;
}
int main(){
    ListNode*h=NULL;
    insert(7,&h);
    insert(6,&h);
    insert(5,&h);
    insert(4,&h);
    insert(3,&h);
    insert(2,&h);
    insert(1,&h);
    print(h);
    ListNode *r=reverseKGroup2(h,3);
    print(r);
}