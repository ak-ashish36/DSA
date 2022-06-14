// https://leetcode.com/problems/add-two-numbers/
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
void insertAtTail(ListNode* &tail,int val){
    ListNode *node = new ListNode(val);
    if(tail==NULL){tail=node; return;}
        tail->next=node;
        tail=node;
}
ListNode*AddTwoNumbers(ListNode*head1,ListNode*head2){
    int carry=0;
    ListNode *newList = new ListNode();
    ListNode *newListTail = newList;
    while(head1 != NULL || head2!=NULL || carry){
        int val1=0,val2=0;
        if(head1!=NULL){
            val1=head1->val;
        }
        if(head2!=NULL){
            val2=head2->val;
        }
        int sum=val1+val2+carry;
        carry=sum/10;
        int digit = sum%10;
        insertAtTail(newListTail,digit);
        if(head1 != NULL){
            head1=head1->next;
        }
        if(head2!=NULL){
            head2=head2->next;
        }
    }
    return newList->next;
}
int main(){
    ListNode* head1=NULL;
    insert(9,&head1);
    insert(9,&head1);
    insert(9,&head1);
    insert(9,&head1);
    insert(9,&head1);
    insert(9,&head1);
    insert(9,&head1);

    ListNode* head2=NULL;
    insert(9,&head2);
    insert(9,&head2);
    insert(9,&head2);
    insert(9,&head2);
    print(head1);
    print(head2);

    ListNode*h=AddTwoNumbers(head1,head2);
    print(h);
}