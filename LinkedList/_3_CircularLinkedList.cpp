#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this-> next=nullptr;
    }
};
class CircularLinkedList{
    Node *last;
    public:
    CircularLinkedList(){
        last=NULL;
    }
    void insertAtfirst(int value){
        if(last==NULL){
            Node *new_node=new Node(value);
            last=new_node;
            last->next=last;
        }else{
            Node *new_node=new Node(value);
            new_node->next=last->next;
            last->next=new_node;
        }  
    }
    void insertAtEnd(int value){
        if(last==NULL){
            Node *new_node=new Node(value);
            last=new_node;
            last->next=last;
        }else{
            Node *new_node=new Node(value);
            new_node->next=last->next;
            last->next=new_node;
            last=new_node;
        } 
    }
    void insertAfterValue(int value,int given_value){
        if(last==NULL){cout<<"List is empty\n";return;}
        Node *new_node=new Node(value);
        Node *ptr=last->next;
        do{
            ptr=ptr->next;
        }
        while(ptr->data!=given_value && ptr->next!=last->next);
        if(ptr->data==given_value){
            new_node->next=ptr->next;
            ptr->next=new_node;
            if(ptr==last){
                last=new_node;
            }
        }else if(ptr->next->data==given_value){
            ptr=ptr->next;
            new_node->next=ptr->next;
            ptr->next=new_node;
            if(ptr==last){
                last=new_node;
            }
        }else{cout<<"Given Value is not present\n";}
    }
    void deleteValue(int value){
        if(last==NULL){cout<<"List is already empty\n";return;}
        Node *ptr=last;
        Node *ptr2=last->next;
        do{
            ptr2=ptr2->next;
            ptr=ptr->next;
        }
        while(ptr2->data!=value && ptr2->next!=last->next);
        if(ptr2->data==value){
            ptr->next=ptr2->next;
            free(ptr2);
        }
        else if(ptr2->next->data==value){
            ptr2=ptr2->next;
            ptr=ptr->next;
            ptr->next=ptr2->next;
            free(ptr2);
        }else{cout<<"Given Value is not present\n";}
    }
    void print(){
        if(last==NULL){cout<<"List is empty\n";return;}
        Node *temp =last->next;
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while (temp!=last->next);
        cout<<endl;
    }
};
int main(){
    CircularLinkedList obj;
    obj.insertAtfirst(1);
    obj.insertAtfirst(2);
    obj.insertAtEnd(4);
    obj.insertAfterValue(5,4);
    obj.insertAfterValue(9,2);
    obj.print();
    obj.deleteValue(2);
    obj.print();
   return 0;
}