// https://leetcode.com/problems/palindrome-linked-list/
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
ListNode* middleElement(ListNode* head){
    ListNode *slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    free(fast);
    return slow; 
}
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
// Time Complexity: O(N)  Space Complexity: O(N)
bool isPalindrome(ListNode* head) {
    vector<int> arr;
    while(head != NULL) {
        arr.push_back(head->val);
        head = head->next;
    }
    for(int i=0;i<arr.size()/2;i++) 
        if(arr[i] != arr[arr.size()-i-1]) return false;
    return true;
}
// Time Complexity: O(N/2)+O(N/2)+O(N/2)  Space Complexity: O(1)
bool isPalindrome2(ListNode* head) {
    if(head==NULL || head->next==NULL) return true;
    ListNode *middleElem=middleElement(head);
    ListNode*h1=head;
    ListNode*h2=reverseList(middleElem->next);
    while(h2!=NULL){
        if(h1->val!=h2->val){
            return false;
        }
        h1=h1->next;
        h2=h2->next;
    }
    return true;
}
int main(){
    ListNode* head=NULL;
    insertAtBack(head,1);
    insertAtBack(head,2);
    insertAtBack(head,2);
    insertAtBack(head,1);
    print(head);
    cout<<isPalindrome(head);
}