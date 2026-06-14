#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <iostream>

/*
 * CIRCULAR QUEUE IMPLEMENTATION
 * 
 * WHY CIRCULAR QUEUE?
 * - Solves memory waste problem of simple queue
 * - Reuses freed space at front after dequeues
 * - Efficient memory utilization for fixed-size scenarios
 * 
 * WHY NOT SIMPLE QUEUE?
 * - Simple queue: front spaces become unusable after dequeue
 * - Wastes memory even when queue has space
 * - Requires shifting elements or dynamic resizing
 * 
 * TIME COMPLEXITY:
 * - Enqueue: O(1)
 * - Dequeue: O(1)
 * - Front: O(1)
 * 
 * SPACE COMPLEXITY: O(n)
 * 
 * MEMORY OPTIMIZATION:
 * Simple Queue: After 5 dequeues from 10-size queue:
 *   [X][X][X][X][X][6][7][8][9][10]
 *   5 spaces wasted, can't reuse
 * 
 * Circular Queue: Same scenario:
 *   [11][12][X][X][X][6][7][8][9][10]
 *   Front spaces reused efficiently
 */

template <typename T>
class CircularQueue {
private:
    static const int MAX_SIZE = 1000;
    T arr[MAX_SIZE];
    int front;
    int rear;
    int size;

public:
    CircularQueue() : front(0), rear(-1), size(0) {}
    
    // Enqueue element - O(1)
    bool enqueue(const T& value) {
        if(size >= MAX_SIZE) {
            std::cout << "Circular Queue Full!" << std::endl;
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
            std::cout << "Circular Queue Empty!" << std::endl;
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
    
    // Check if full
    bool isFull() const {
        return size >= MAX_SIZE;
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
    
    // Display queue
    void display() const {
        if(isEmpty()) {
            std::cout << "Circular Queue is empty" << std::endl;
            return;
        }
        std::cout << "Circular Queue: ";
        for(int i = 0; i < size; i++) {
            int index = (front + i) % MAX_SIZE;
            std::cout << arr[index];
            if(i < size - 1) std::cout << " <- ";
        }
        std::cout << std::endl;
    }
};

#endif
