//https://leetcode.com/problems/reverse-linked-list-ii/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head,int left,int right) {
    if(head==nullptr || head->next==nullptr || left==right){return head;}
        ListNode* temp1 =new ListNode(0);
        temp1->next=head;
        ListNode *temp2=head;
        
        for(int i=1;i<=right;i++){                  //  1 -> 2 -> 3 -> 4 -> 5       ->   1->4->3->2->5
            temp2=temp2->next;                      //  |                   |
            if(i<left){                             // temp1               temp2
                temp1=temp1->next;
            }
        }
    
        ListNode *prev=temp2;
        ListNode *curr=temp1->next;
        ListNode * forward;
        while(curr!=temp2){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }

        temp1->next=prev;
        
        if(left==1){return temp1->next;}
        return head; 
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
    ListNode* h1=new ListNode(5);
    ListNode* h2=new ListNode(4,h1);
    ListNode* h3=new ListNode(3,h2);
    ListNode* h4=new ListNode(2,h3);
    ListNode* h5=new ListNode(1,h4);
    print(h5);
    ListNode* newh=reverseList(h5,2,4);
    print(newh);
    return 0;
}