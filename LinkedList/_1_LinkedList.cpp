#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(){
        data=0; 
        this->next=nullptr;
    }
    Node(int data){
        this->data=data;
        this-> next=nullptr;
    }
};
class LinkedList{
    Node *head;
    public:
    LinkedList(){
        head=NULL;
    }
    void insertAthead(int value){
        Node *temp=new Node(value);
        temp->next=head;
        head=temp;
    }
    void insertAtLast(int value){
        Node *temp=new Node(value);
        if (head == NULL) {
           head = temp;
        }
        Node *ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=NULL;
    }
    void insertAtPosition(int value,int position){
        if(position==0){insertAthead(value); return;}
        Node *temp=new Node(value);
        Node *ptr=head;
        for(int i=0;i<position-1;i++){
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
    void insertAfterValue(int new_value,int value){
        Node *temp=new Node(new_value);
        Node *ptr=head;
        while(ptr->data!=value && ptr->next!=NULL){
            ptr=ptr->next;
        }
        if(ptr->data==value){
            temp->next=ptr->next;
            ptr->next=temp;
        }
    }
    void deleteAtFirst(){
        // Node *ptr=head;
        head=head->next;
        // free(ptr);
    }
    void deleteAtLast(){
        Node *ptr=head;
        Node *ptr2=head->next;
        while(ptr2->next !=NULL){
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        ptr->next=ptr2->next;
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
        free(ptr2);
    }
    void deleteAtValue(int value){
        Node *ptr=head;
        Node *ptr2=head->next;
        while(ptr2->data!=value && ptr2->next!=NULL){
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        if(ptr2->data==value){
            ptr->next=ptr2->next;
            free(ptr2);
        }
    }
    bool searchValue(int value){
        Node *ptr=head;
        while(ptr!=NULL){
            if(ptr->data==value){return true;}
            ptr=ptr->next;
        }
        return false;
    }
    void print(){
        Node *temp=head;
        while (temp != NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList obj;   
    obj.insertAthead(8);
    obj.insertAthead(7);
    obj.insertAtLast(13);
    obj.insertAtPosition(64,3);
    obj.insertAfterValue(9,64);
    obj.print();
    cout<<"After Deletion\n";
    // obj.deleteAtFirst();
    // obj.deleteAtLast();
    // obj.deleteAtIndex(3);
    obj.deleteAtValue(8);
    obj.print();
    cout<<obj.searchValue(9);


   return 0;
}