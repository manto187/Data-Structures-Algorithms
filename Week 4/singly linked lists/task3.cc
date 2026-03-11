#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{

private:
    Node* head;

public:
    LinkedList(){
        head=NULL;
    }

    void addAtStart(int value){

        Node* newNode=new Node();

        newNode->data=value;
        newNode->next=head;

        head=newNode;
    }

    void addAtPosition(int value,int position){

        if(position==1){
            addAtStart(value);
            return;
        }

        Node* newNode=new Node();
        newNode->data=value;

        Node* temp=head;

        for(int i=1;i<position-1;i++){
            temp=temp->next;
        }

        newNode->next=temp->next;
        temp->next=newNode;
    }

    void display(){

        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }

        cout<<"NULL\n";
    }
};

int main(){

    LinkedList list;

    list.addAtStart(10);
    list.addAtStart(20);
    list.addAtPosition(15,2);

    list.display();

    return 0;
}