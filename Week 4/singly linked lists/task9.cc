#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;

};

class singlyLinkedList{
    private:
    Node* head;
    public:
    singlyLinkedList(){
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
    void deleteAtPosition(int position){
        if(position==1){
            Node* temp=head;
            head=head->next;

            delete temp;
            return;
        }
        Node* temp=head;

        for(int i=1; i<position-1; i++){
            temp=temp->next;
        }
        Node* nodeToDelete=temp->next;
        temp->next=nodeToDelete->next;
        delete nodeToDelete;
    }
    void display(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    singlyLinkedList list;

    list.addAtEnd(10);
    list.addAtEnd(20);
    list.addAtEnd(30);
    list.addAtEnd(40);

    list.deleteAtPosition(3);
    list.display();
}