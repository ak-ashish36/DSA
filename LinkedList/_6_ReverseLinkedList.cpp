//https://leetcode.com/problems/reverse-linked-list/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL){return head;}
    ListNode * prev=NULL;
    ListNode * curr=head;
    ListNode * forward;
    while(curr != NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;  
}
void print(ListNode*head){
        ListNode *temp=head;
        while (temp != NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
int main(){
    ListNode* h1=new ListNode(1);
    ListNode* h2=new ListNode(2,h1);
    ListNode* h3=new ListNode(3,h2);
    print(h3);
    h3=reverseList(h3);
    print(h3);
    return 0;
}