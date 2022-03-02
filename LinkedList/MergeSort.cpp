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
ListNode*findMid(ListNode*head){
    ListNode*slow=head;
    ListNode*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;   
}
ListNode*merging(ListNode*head1,ListNode*head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    ListNode *mergedList = new ListNode();
    ListNode *mergedListTail = mergedList;

    while(head1!=NULL && head2 !=NULL){
        if(head1->val > head2->val){
            mergedListTail->next=head2;
            mergedListTail=head2;
            head2=head2->next;
        }
        else{
            mergedListTail->next=head1;
            mergedListTail=head1;
            head1=head1->next;
        }
    }
    while(head1!=NULL){
        mergedListTail->next=head1;
        mergedListTail=head1;
        head1=head1->next;
    }
    while(head2!=NULL){
        mergedListTail->next=head2;
        mergedListTail=head2;
        head2=head2->next;
    }
    return mergedList->next;
}
ListNode*mergesort(ListNode*head){
    if(head==NULL || head->next==NULL) return head;
    ListNode*mid=findMid(head);
    ListNode*left=head;
    ListNode*right=mid->next;
    mid->next=NULL;
    left=mergesort(left);
    right=mergesort(right);
    ListNode*result=merging(left,right);
    return result;
}
int main(){
     ListNode* head=NULL;
    insertAtBack(head,5);
    insertAtBack(head,3);
    insertAtBack(head,8);
    insertAtBack(head,9);
    insertAtBack(head,7);
    print(head);
    head=mergesort(head);
    print(head);
}