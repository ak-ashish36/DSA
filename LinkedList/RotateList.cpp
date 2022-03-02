// https://leetcode.com/problems/rotate-list/description/
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
int lengthoflist(ListNode*head){
    int lenght=0;
    while(head!=NULL){
        head=head->next;
        lenght++;
    }
    return lenght;
}
// Time Complexity:O(N) + O(N–(N%k))  Space Complexity: O(1)
ListNode* rotate(ListNode*head, int k){
    if(head==NULL || head->next==NULL)return head;
    ListNode*currhead=head;
    while(k!=0){
        ListNode*temp=currhead;
        while (temp->next->next!=NULL){
            temp=temp->next;
        }
        ListNode*newhead=temp->next;
        newhead->next=currhead;
        currhead=newhead;
        temp->next=NULL;
        k--;
    }
    return currhead;
}
ListNode* rotate2(ListNode*head, int k){
    if(head==NULL || head->next==NULL)return head;
    int lenght=lengthoflist(head);
    if(k>=lenght){
        k=k%lenght;
    }
    ListNode*currhead=head;
    while(k!=0){
        ListNode*temp=currhead;
        while (temp->next->next!=NULL){
            temp=temp->next;
        }
        ListNode*newhead=temp->next;
        newhead->next=currhead;
        currhead=newhead;
        temp->next=NULL;
        k--;
    }
    return currhead;
}
int main(){
    ListNode* head=NULL;
    insertAtBack(head,1);
    insertAtBack(head,2);
    insertAtBack(head,3);
    insertAtBack(head,4);
    insertAtBack(head,5);

    print(head);
    ListNode* node=rotate2(head,20000000);
    print(node);
}