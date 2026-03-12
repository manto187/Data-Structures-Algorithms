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

    singlyLinkedList() {
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

    void deleteLastNode() {

        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {

            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void display() {

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL"<<endl;
    }
};

int main() {

    singlyLinkedList list;

    list.addAtEnd(10);
    list.addAtEnd(20);
    list.addAtEnd(30);

    list.deleteLastNode();

    list.display();

    return 0;
}