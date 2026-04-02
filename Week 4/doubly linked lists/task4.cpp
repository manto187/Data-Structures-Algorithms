#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

class DoublyLinkedList {
    DNode* head;

public:
    DoublyLinkedList() { head = NULL; }

    void add(int val) {
        DNode* n = new DNode{val,NULL,NULL};
        if(!head){ head=n; return; }

        DNode* t=head;
        while(t->next) t=t->next;
        t->next=n;
        n->prev=t;
    }

    void updateFirst(int val) {
        if(head) head->data = val;
    }

    void display(){
        DNode* t=head;
        while(t){
            cout<<t->data<<" <-> ";
            t=t->next;
        }
        cout<<"NULL\n";
    }
};

int main(){
    DoublyLinkedList list;
    list.add(10);
    list.add(20);
    list.add(30);

    list.updateFirst(100);
    list.display();
}