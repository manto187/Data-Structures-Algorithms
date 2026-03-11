#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList{
    private:
    Node* head;
    
    public:
    SinglyLinkedList(){
        head = NULL;
    }
// display the singly linked list
void display(){
    if(head==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}};