//https://leetcode.com/problems/merge-two-sorted-lists/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
void insertAtBack(ListNode* &head,int val){
    ListNode *node = new ListNode(val);
    if(head==NULL){head=node; return;}
    ListNode *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=node;
        node->next=NULL;
}
// T=O(n+m) S=O(n+m)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *newList = NULL;
    while(list1!=NULL || list2!=NULL){
        if(list1==NULL){
            insertAtBack(newList,list2->val);
            list2=list2->next; 
        }
        else if(list2==NULL){
            insertAtBack(newList,list1->val);
            list1=list1->next;
        }
        else if(list1->val >= list2->val){
            insertAtBack(newList,list2->val);
            list2=list2->next;
        }
        else if(list1->val < list2->val){
            insertAtBack(newList,list1->val);
            list1=list1->next;
        } 
    }
    return newList;
}
void insertAtTail2(ListNode* &newTail,ListNode * &currentnode){
    newTail->next=currentnode;
    newTail=currentnode;
}
// T=O(n+m) S=O(1)
ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
    ListNode *newList = new ListNode();
    ListNode *newListTail = newList;
    while(list1!=NULL || list2!=NULL){
        if(list1==NULL){
            insertAtTail2(newListTail,list2);
            break;
        }
        else if(list2==NULL){
            insertAtTail2(newListTail,list1);
            break;
        }
        else if(list1->val >= list2->val){
            insertAtTail2(newListTail,list2);
            list2=list2->next;
        }
        else if(list1->val < list2->val){
            insertAtTail2(newListTail,list1);
            list1=list1->next;
        }
    }
    return newList->next;
}
int main(){
    ListNode* head1=NULL;
    insertAtBack(head1,1);
    insertAtBack(head1,2);
    insertAtBack(head1,4);
    insertAtBack(head1,5);
    insertAtBack(head1,7);

    ListNode* head2=NULL;
    insertAtBack(head2,2);
    insertAtBack(head2,3);
    insertAtBack(head2,5);
    print(head1);
    print(head2);
    ListNode* merged=mergeTwoLists2(head1,head2);
    print(merged);
    return 0;
}