// https://www.youtube.com/watch?v=kvCYxPKpPGg&list=PLUcsbZa0qzu3yNzzAxgvSgRobdUUJvz7p&index=52&ab_channel=AnujBhaiya
#include<bits/stdc++.h>
using namespace std;
struct Node{
        int data;
        Node *next;
        Node *down;
        Node(int data=0){
            this->data=data;
            this-> next=nullptr;
            this->down=nullptr;
        }
};
void flattenList(Node *head){
    Node *curr=head;
    queue<Node*>q;

    while(curr!=NULL){
       if(curr->down!=NULL){
           q.push(curr->down);
       } 
       if(curr->next==NULL){
            curr->next=q.front();
            q.pop();
        }

        curr=curr->next;
    }
}
void flattenList2(Node *head){
    Node *temp=NULL;

    Node *tail=head;

    while(tail->next != NULL){
        tail=tail->next;
    }

    Node *curr=head;
    while(curr!=NULL){

        if(curr->down != NULL){
            tail->next=curr->down;
    
            temp=curr->down;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            tail=temp;
        }
        curr=curr->next;
    }

}
int main(){
     
    return 0;
}