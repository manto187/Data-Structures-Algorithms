#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

class SinglyLinkedList{
    private: 
    Node* head;
    public:
    SinglyLinkedList(){
        head=NULL;
    }

    void addAtEnd(int value){
        Node* newNode=new Node();
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    void UpdateLastNode(int value){
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->data=value;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};
int main(){
    SinglyLinkedList list;
    
    list.addAtEnd(10);
    list.addAtEnd(20);
    list.addAtEnd(30);

    list.UpdateLastNode(300);
    list.display();
    
}