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

    void addAtEnd(int value) {
        DNode* newNode = new DNode();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            return;
        }

        DNode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    void addAtPosition(int value, int pos) {
        DNode* newNode = new DNode();
        newNode->data = value;

        if (pos == 1) {
            newNode->prev = NULL;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        DNode* temp = head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void display() {
        DNode* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList list;
    list.addAtEnd(10);
    list.addAtEnd(20);
    list.addAtEnd(30);

    list.addAtPosition(15, 2);

    list.display();
}