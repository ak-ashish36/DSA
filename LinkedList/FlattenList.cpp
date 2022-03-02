//https://www.codingninjas.com/codestudio/problems/1112655?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct ListNode {
    int val;
    ListNode *next;
    ListNode *bottom;
    ListNode() : val(0), next(nullptr),bottom(nullptr) {}
    ListNode(int x) : val(x), next(nullptr),bottom(nullptr) {}
};
void print(ListNode*head){
        ListNode *temp=head;
        while (temp != NULL){
            ListNode *temp2=temp->bottom;
            cout<<temp->val<<"->";
            while(temp2!=NULL){
                cout<<temp2->val<<"*";
                temp2=temp2->bottom;
            }
            cout<<"\t";
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
void insertAtBottomBack(ListNode* &head,int val){
    ListNode *node = new ListNode(val);
    if(head==NULL){head=node; return;}
    ListNode *ptr=head;
        while(ptr->bottom!=NULL){
            ptr=ptr->bottom;
        }
        ptr->bottom=node;
        node->bottom=NULL;
}
void insertAtTail(ListNode* &Tail,ListNode * &currentnode){
    Tail->bottom=currentnode;
    Tail=currentnode;
}
// T=O(n+m) S=O(1)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *newList = new ListNode();
    ListNode *newListTail = newList;
    while(list1!=NULL || list2!=NULL){
        if(list1==NULL){
            insertAtTail(newListTail,list2);
            break;
        }
        else if(list2==NULL){
            insertAtTail(newListTail,list1);
            break;
        }
        else if(list1->val >= list2->val){
            insertAtTail(newListTail,list2);
            list2=list2->bottom;
        }
        else if(list1->val < list2->val){
            insertAtTail(newListTail,list1);
            list1=list1->bottom;
        }
    }
    return newList->bottom;
}
ListNode *flatten(ListNode *root){
    if (root == NULL || root->next == NULL) 
        return root; 
    // recur for list on right 
    root->next = flatten(root->next); 
    // now merge 
    root = mergeTwoLists(root, root->next); 
    // return the root 
    // it will be in turn merged with its left 
        return root; 
}
int main(){
    ListNode* head=NULL;
    insertAtBack(head,1);
    insertAtBottomBack(head,2);
    insertAtBottomBack(head,3);

    insertAtBack(head,4);
    insertAtBottomBack(head->next,5);
    insertAtBottomBack(head->next,6);

    insertAtBack(head,7);
    insertAtBottomBack(head->next->next,8);

    insertAtBack(head,9);
    insertAtBottomBack(head->next->next->next,12);

    insertAtBack(head,20);

    print(head);

    ListNode* flatlist=flatten(head);
    print(head);

    // print(flatlist);
    return 0;
}