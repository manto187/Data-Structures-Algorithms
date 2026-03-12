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
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if(head==NULL){
            head=newNode;
        }
        else{
            Node* temp = head;

            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }
    }

    void updateAtPosition(int value, int position){
        Node* temp = head;

        for(int i=1; i<position; i++){
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
        cout<<"NULL"<<endl;
    }
};

int main(){
    singlyLinkedList list;
    list.addAtEnd(10);
    list.addAtEnd(20);
    list.addAtEnd(30);

    list.updateAtPosition(200, 2);
    list.display();

}