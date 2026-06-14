#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

/*
 * DOUBLY LINKED LIST IMPLEMENTATION
 * 
 * WHY DOUBLY LINKED LIST?
 * - Supports bidirectional traversal (forward and backward)
 * - Efficient deletion when node pointer is known - O(1)
 * - Better for navigation history (like browser back/forward)
 * 
 * WHY NOT SINGLY LINKED LIST?
 * - Cannot traverse backward efficiently
 * - Requires traversal from head to go back
 * - Delete operation needs previous node reference
 * 
 * TIME COMPLEXITY:
 * - Insert at head: O(1)
 * - Insert at tail: O(1) with tail pointer
 * - Delete node: O(1) if node pointer known
 * - Search: O(n)
 * - Traverse forward/backward: O(n)
 * 
 * SPACE COMPLEXITY: O(n)
 * 
 * MEMORY EFFICIENCY:
 * - Two pointers per node (prev + next)
 * - Higher memory overhead than singly linked list
 * - But enables O(1) bidirectional operations
 */

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    Node* current;  // For navigation
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), current(nullptr), size(0) {}
    
    ~DoublyLinkedList() {
        clear();
    }
    
    // Insert at end - O(1) with tail pointer
    void insert(const T& value) {
        Node* newNode = new Node(value);
        
        if(!head) {
            head = tail = current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            current = tail;
        }
        size++;
    }
    
    // Move to previous - O(1)
    bool movePrevious() {
        if(current && current->prev) {
            current = current->prev;
            return true;
        }
        return false;
    }
    
    // Move to next - O(1)
    bool moveNext() {
        if(current && current->next) {
            current = current->next;
            return true;
        }
        return false;
    }
    
    // Get current value
    T* getCurrent() {
        if(current) {
            return &(current->data);
        }
        return nullptr;
    }
    
    // Display forward
    void displayForward() const {
        Node* temp = head;
        std::cout << "Forward: ";
        while(temp) {
            std::cout << temp->data;
            if(temp->next) std::cout << " <-> ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    
    // Display backward
    void displayBackward() const {
        Node* temp = tail;
        std::cout << "Backward: ";
        while(temp) {
            std::cout << temp->data;
            if(temp->prev) std::cout << " <-> ";
            temp = temp->prev;
        }
        std::cout << std::endl;
    }
    
    // Get size
    int getSize() const {
        return size;
    }
    
    // Check if empty
    bool isEmpty() const {
        return head == nullptr;
    }
    
    // Clear all nodes
    void clear() {
        while(head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = current = nullptr;
        size = 0;
    }
    
    // Check if can go back
    bool canGoBack() const {
        return current && current->prev;
    }
    
    // Check if can go forward
    bool canGoForward() const {
        return current && current->next;
    }
};

#endif
