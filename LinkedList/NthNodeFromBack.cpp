//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
// T=O(2n)  S=O(1)
void deleteNthNode(ListNode* &head,int n){
    ListNode*temp=head;
    int totalnodes=1;
    while(temp->next!=NULL){
        totalnodes++;
        temp=temp->next;
    }
    int x=totalnodes-n+1;
    if(x==1){
        head=head->next;
        return;
    }
    ListNode*prev=head;
    ListNode*next=head->next;
    for(int i=1;i<x-1;i++){
        prev=prev->next;
        next=next->next;
    }
    prev->next=next->next;
    free(next);
}
// T=O(n)  S=O(1)
ListNode* deleteNthNode2(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start->next=head;   
        ListNode* next = start;
        ListNode* prev= start;  
        for(int i = 1; i <= n; ++i){
            next = next->next;
        }
        while(next->next != NULL){
            next = next->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return start->next;
    }
int main(){
    ListNode* h1=NULL;
    insert(1,&h1);
    insert(2,&h1);
    insert(3,&h1);
    insert(4,&h1);
    insert(5,&h1);
    insert(6,&h1);
    print(h1);
    // deleteNthNode(h1,6);
    h1=deleteNthNode2(h1,3);
    print(h1);
    return 0;
}