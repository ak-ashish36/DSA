//https://leetcode.com/problems/copy-list-with-random-pointer/
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
void print(Node*head){
        Node *temp=head;
        while (temp != NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<endl;
}
void insertAtBack(Node*&head,int val) {
    Node*newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node*temp = head;
    while(temp->next != NULL){ temp = temp->next;}
    temp->next = newNode;
    return;
}
void insertatRandom(Node*&head,int value,int index){
    Node*ptr=head;
    while(ptr->val!=value){
        ptr=ptr->next;
    }
    // cout<<"\n"<<ptr->val<<" ";
    if(index==-1){ptr->random=nullptr;return;}
    Node*ptr2=head;
    for(int i=0;i<index;i++){
        ptr2=ptr2->next;
    }
    ptr->random=ptr2;
    // cout<<ptr2->val;
}
void insertAtTail(Node* &Tail,int value){
    Node*newNode = new Node(value);
    Tail->next=newNode;
    Tail=newNode;
}
Node*clone(Node*head){
    Node* cloneHead = new Node(0);
    Node* cloneTail = cloneHead;
    unordered_map<Node*,Node*> map;
    Node*temp=head;
    while(temp!=NULL){
        insertAtTail(cloneTail,temp->val);
        map[temp]=cloneTail;
        temp=temp->next;
    }
    temp = head;
    Node*clonetemp = cloneHead->next;
    while(temp!=NULL){
        clonetemp->random=map[temp->random];
        temp = temp -> next;
        clonetemp = clonetemp->next;
    }
    return cloneHead->next;
}
Node *clone2(Node*head){
    Node*temp=head;
    //Inserting clone node after its original node 
    while(temp!=NULL){
        Node *node=new Node(temp->val);
        node->next=temp->next;
        temp->next=node;
        temp=temp->next->next;
    }
    //Inserting random to clone node
    temp=head;
    while(temp!=NULL){
        if(temp->random==NULL){
            temp->next->random=NULL;
            temp=temp->next->next;
        }
        else{
        temp->next->random=temp->random->next;
        temp=temp->next->next;
        }
    }
    //Linking all the clone nodes to single list
    Node* cloneHead = new Node(0);
    Node* cloneTail = cloneHead;
    temp=head;
    while(temp!=NULL){
        cloneTail->next=temp->next;
        cloneTail=temp->next;
        //Getting back original list
        temp->next=temp->next->next;
        temp=temp->next;
    }
    return cloneHead->next;
}
int main(){
    Node* head=NULL;
    insertAtBack(head,7);
    insertAtBack(head,13);
    insertAtBack(head,11);
    insertAtBack(head,10);
    insertAtBack(head,1);
    print(head);
    insertatRandom(head,7,-1);
    insertatRandom(head,13,0);
    insertatRandom(head,11,4);
    insertatRandom(head,10,2);
    insertatRandom(head,1,2); 
    Node* copy=clone2(head);
    // print(copy);
    // cout<<copy->next->next->random->val;
    return 0;
}