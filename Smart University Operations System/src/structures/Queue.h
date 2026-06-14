#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

/*
 * QUEUE IMPLEMENTATION (FIFO - First In First Out)
 * 
 * WHY QUEUE?
 * - Perfect for FIFO operations (complaint handling, task scheduling)
 * - Fair processing - first request served first
 * - Natural model for waiting lines, job scheduling
 * 
 * WHY NOT STACK?
 * - Stack is LIFO - processes most recent first
 * - Unfair for complaint systems (newest gets priority)
 * - Violates fairness principle for service queues
 * 
 * TIME COMPLEXITY:
 * - Enqueue: O(1)
 * - Dequeue: O(1)
 * - Front: O(1)
 * - Search: O(n)
 * 
 * SPACE COMPLEXITY: O(n)
 * 
 * MEMORY EFFICIENCY:
 * - Array-based: wasted space at front after dequeues
 * - Circular queue solves this problem
 * - Linked list: no wasted space, extra pointer overhead
 */

template <typename T>
class Queue {
private:
    static const int MAX_SIZE = 1000;
    T arr[MAX_SIZE];
    int front;
    int rear;
    int size;

public:
    Queue() : front(0), rear(-1), size(0) {}
    
    // Enqueue element - O(1)
    bool enqueue(const T& value) {
        if(size >= MAX_SIZE) {
            std::cout << "Queue Overflow!" << std::endl;
            return false;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        size++;
        return true;
    }
    
    // Dequeue element - O(1)
    bool dequeue() {
        if(isEmpty()) {
            std::cout << "Queue Underflow!" << std::endl;
            return false;
        }
        front = (front + 1) % MAX_SIZE;
        size--;
        return true;
    }
    
    // Get front element - O(1)
    T* getFront() {
        if(isEmpty()) {
            return nullptr;
        }
        return &arr[front];
    }
    
    // Check if empty
    bool isEmpty() const {
        return size == 0;
    }
    
    // Get size
    int getSize() const {
        return size;
    }
    
    // Clear queue
    void clear() {
        front = 0;
        rear = -1;
        size = 0;
    }
    
    // Display queue contents
    void display() const {
        if(isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }
        std::cout << "Queue (front to rear): ";
        for(int i = 0; i < size; i++) {
            int index = (front + i) % MAX_SIZE;
            std::cout << arr[index];
            if(i < size - 1) std::cout << " <- ";
        }
        std::cout << std::endl;
    }
};

#endif
