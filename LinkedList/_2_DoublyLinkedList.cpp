#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int data){
        this->data=data;
        this-> next=NULL;
        this->prev=NULL;
    }
};
class doublyLinkedList{
    Node *head;
    public:
    doublyLinkedList(){
        head=NULL;
    }
    void insertAtHead(int value){
        Node *new_node=new Node(value);
        if(head==NULL){
            head=new_node;
        }else{
            new_node->next=head;
            head->prev=new_node;
            head=new_node;
        }
    }
    void insertAtTail(int value){
        Node *new_node=new Node(value);
        Node *ptr=head;
        while(ptr->next != NULL){
            ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->prev=ptr;
    }
    void insertAtIndex(int value,int index){
        if(index==0){insertAtHead(value); return;}
        Node *new_node=new Node(value);
        Node *ptr=head;
        for(int i=0;i<index-1;i++){
            ptr=ptr->next;
        }
        new_node->next=ptr->next;
        ptr->next->prev=new_node;
        new_node->prev=ptr;
        ptr->next=new_node;
    }
    void insertAtValue(int value,int node_value){
        Node *new_node=new Node(value);
        Node *ptr=head;
        while(ptr->data!=node_value && ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->data=value;
    }
    void deleteAtHead(){
        head=head->next;
        head->prev=NULL;
    }
    void deleteAtTail(){
        Node *ptr=head;
        Node *ptr2=head->next;
        while(ptr2->next != NULL){
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        ptr2->prev=NULL;
        ptr->next=NULL;
        free(ptr2);
        
    }
    void deleteAtIndex(int index){
        Node *ptr=head;
        Node *ptr2=head->next;
        for(int i=0;i<index-1;i++){
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        ptr->next=ptr2->next;
        ptr2->next->prev=ptr;
        ptr2->next=NULL;
        ptr2->prev=NULL;
        free(ptr2); 
    }
    void deleteAtValue(int value){
        Node *ptr=head;
        Node *ptr2=head->next;
        while(ptr2->data != value && ptr2->next!=NULL){
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        ptr->next=ptr2->next;
        ptr2->next->prev=ptr;
        ptr2->next=NULL;
        ptr2->prev=NULL;
        free(ptr2);
    }
    void print(){
        Node *temp=head;
        while (temp != NULL){
            cout<<temp->data<<"<->";
            temp=temp->next;
        }
        cout<<endl;
    }
    void printBackward(){
        Node *tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        while(tail!=NULL){
            cout<<tail->data<<"->";
            tail=tail->prev;
        }
        cout<<endl;
    }
};
int main(){
    doublyLinkedList obj;
    obj.insertAtHead(1);
    obj.insertAtHead(9);
    obj.insertAtTail(4);
    obj.insertAtTail(2);
    obj.insertAtIndex(0,4);
    obj.insertAtValue(5,4);
    obj.print();
    obj.printBackward();
    cout<<"After Deletion\n";
    // obj.deleteAtHead();
    // obj.deleteAtTail();
    obj.deleteAtIndex(4);
    obj.deleteAtValue(5);
    obj.print();
    obj.printBackward();
   return 0;
}