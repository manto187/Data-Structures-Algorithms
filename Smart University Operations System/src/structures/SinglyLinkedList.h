#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

/*
 * SINGLY LINKED LIST IMPLEMENTATION
 * 
 * WHY SINGLY LINKED LIST?
 * - Efficient insertion/deletion at any position (O(1) after locating node)
 * - Dynamic size - no need for resizing like arrays
 * - No wasted memory from pre-allocation
 * 
 * WHY NOT ARRAY?
 * - Arrays require O(n) time for insertion/deletion (element shifting)
 * - Arrays waste memory or face size limitations
 * - No efficient way to insert in middle of array
 * 
 * TIME COMPLEXITY:
 * - Insert at head: O(1)
 * - Insert at tail: O(n) without tail pointer
 * - Delete at head: O(1)
 * - Search: O(n)
 * - Access by index: O(n)
 * 
 * SPACE COMPLEXITY: O(n)
 * 
 * MEMORY EFFICIENCY:
 * - Extra pointer per node (overhead)
 * - No contiguous memory (less cache-friendly)
 * - But no wasted pre-allocated space
 */

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    int size;

public:
    SinglyLinkedList() : head(nullptr), size(0) {}
    
    ~SinglyLinkedList() {
        clear();
    }
    
    // Insert at beginning - O(1)
    void insertAtHead(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    // Insert at end - O(n)
    void insertAtTail(const T& value) {
        Node* newNode = new Node(value);
        if(!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
    
    // Delete by value - O(n)
    bool deleteByValue(const T& value) {
        if(!head) return false;
        
        if(head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
        
        Node* current = head;
        while(current->next && current->next->data != value) {
            current = current->next;
        }
        
        if(current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
            return true;
        }
        
        return false;
    }
    
    // Search - O(n)
    bool search(const T& value) const {
        Node* temp = head;
        while(temp) {
            if(temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    // Display all elements
    void display() const {
        Node* temp = head;
        while(temp) {
            std::cout << temp->data;
            if(temp->next) std::cout << " -> ";
            temp = temp->next;
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
        size = 0;
    }
    
    // Get element at index - O(n)
    T* getAt(int index) {
        if(index < 0 || index >= size) {
            return nullptr;
        }
        Node* temp = head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return &(temp->data);
    }
};

#endif
