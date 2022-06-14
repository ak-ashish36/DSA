//https://leetcode.com/problems/intersection-of-two-linked-lists/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
void print(ListNode*head){
        ListNode *temp=head;
        while (temp != NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<endl;
}
//Time Complexity: O(m*n)  Space Complexity: O(1)
ListNode* intersectionPresent(ListNode* head1,ListNode* head2) {
    while(head2 != NULL) {
        ListNode* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}
//Time Complexity: O(m+n)  Space Complexity: O(n)
ListNode* intersectionPresent2(ListNode* head1,ListNode* head2) {
    unordered_set<ListNode*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
    
}
//Time Complexity: O(2*max(length of list1,length of list2))  Space Complexity: O(1)
ListNode* intersectionPresent3(ListNode* head1,ListNode* head2) {
    ListNode* d1 = head1;
    ListNode* d2 = head2; 
    while(d1 != d2) {
        if(d1==NULL)d1=head2;
        else d1=d1->next;

        if(d2==NULL)d2=head1;
        else d2=d2->next;
    }
    return d1;
}
int main(){
    ListNode* head1=NULL;
    insertAtBack(head1,4);
    insertAtBack(head1,1);
    insertAtBack(head1,8);
    insertAtBack(head1,4);
    insertAtBack(head1,5);
    ListNode* head2=NULL;
    insertAtBack(head2,5);
    insertAtBack(head2,6);
    insertAtBack(head2,1);
    head2->next->next->next=head1->next->next;
    print(head1);
    print(head2);
    ListNode* node=intersectionPresent3(head1,head2);
    print(node);
    return 0;
}