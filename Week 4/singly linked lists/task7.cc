#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class singlyLinkedList {

private:
    Node* head;

public:

    singlyLinkedListinkedList() {
        head = NULL;
    }

    void addAtEnd(int value) {

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {

            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void deleteFirstNode(){
        if(head==NULL){
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
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

    list.deleteFirstNode();

    list.display();
}