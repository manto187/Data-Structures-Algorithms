#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>

/*
 * DYNAMIC ARRAY IMPLEMENTATION
 * 
 * WHY DYNAMIC ARRAY?
 * - Supports automatic resizing when capacity is exceeded
 * - Better memory utilization than static arrays
 * - Maintains O(1) random access like static arrays
 * 
 * WHY NOT STATIC ARRAY?
 * - Static arrays waste memory if size is overestimated
 * - Cannot scale dynamically with growing data
 * - Fixed size limitation causes runtime errors on overflow
 * 
 * TIME COMPLEXITY:
 * - Access: O(1)
 * - Insert at end (amortized): O(1)
 * - Insert at position: O(n)
 * - Delete: O(n)
 * - Search: O(n)
 * 
 * SPACE COMPLEXITY: O(n)
 * 
 * MEMORY EFFICIENCY:
 * - Grows by factor of 2 when full (amortized constant time)
 * - Contiguous memory allocation (cache-friendly)
 * - Some wasted space during resizing
 */

template <typename T>
class DynamicArray {
private:
    T* arr;
    int capacity;
    int size;
    
    // Double the capacity when array is full
    void resize() {
        capacity *= 2;
        T* newArr = new T[capacity];
        for(int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    DynamicArray(int initialCapacity = 10) {
        capacity = initialCapacity;
        size = 0;
        arr = new T[capacity];
    }
    
    // Copy Constructor
    DynamicArray(const DynamicArray& other) {
        capacity = other.capacity;
        size = other.size;
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    
    // Copy Assignment Operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            arr = new T[capacity];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    
    ~DynamicArray() {
        delete[] arr;
    }
    
    // Add element at end - O(1) amortized
    void push_back(const T& element) {
        if(size == capacity) {
            resize();
        }
        arr[size++] = element;
    }
    
    // Access element - O(1)
    T& operator[](int index) {
        if(index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }
    
    // Get element at index (const version)
    T get(int index) const {
        if(index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr[index];
    }
    
    // Set element at index
    void set(int index, const T& value) {
        if(index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        arr[index] = value;
    }
    
    // Add element (alias for push_back)
    void add(const T& element) {
        push_back(element);
    }
    
    // Get current size
    int getSize() const {
        return size;
    }
    
    // Get capacity
    int getCapacity() const {
        return capacity;
    }
    
    // Check if empty
    bool isEmpty() const {
        return size == 0;
    }
    
    // Remove element at index - O(n)
    void removeAt(int index) {
        if(index < 0 || index >= size) {
            return;
        }
        for(int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    
    // Clear all elements
    void clear() {
        size = 0;
    }
    
    // Get pointer to internal array
    T* getData() {
        return arr;
    }
};

#endif
