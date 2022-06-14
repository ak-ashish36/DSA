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
void insert(ListNode**head,int value){    //Doing Canges int head so we need not to pass head by reference
    ListNode*newNode = new ListNode(value);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    ListNode*temp = *head;
    while(temp->next != NULL){ temp = temp->next;}
    temp->next = newNode;
    return;
}
ll middleElement(ListNode* head){    //Not doing any changes so we need not to pass head by refernce we can also pass copy
    ListNode *ptr1=head,*ptr2=head;
    while(ptr2!=NULL && ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }
    free(ptr2);
    return ptr1->val; 
}
void delMidElement(ListNode* &head){        //Doing Canges int head so we need not to pass head by reference
    auto ptr1=head,ptr2=head;
    auto prev=head;
    while(ptr2!=NULL && ptr2->next!=NULL){
        prev=ptr1;
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }
    prev->next=ptr1->next;
    free(ptr1);
    free(ptr2);
}
int main(){
    ListNode* h1=NULL;
    insert(&h1,1);
    insert(&h1,2);
    insert(&h1,3);
    insert(&h1,4);
    insert(&h1,5);
    // insert(6,&h1);
    print(h1);
    cout<<middleElement(h1)<<endl;
    // delMidElement(h1);
    // print(h1);
    return 0;
}