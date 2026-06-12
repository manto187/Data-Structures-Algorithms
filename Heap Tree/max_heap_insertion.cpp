#include<iostream>
#include<vector>
using namespace std;
class MaxHeap{
    public:
    vector<int> heap;
    
    void insert(int value){
        heap.push_back(value);

        int i=heap.size() - 1;

        while(i>0){
            int parent = (i-1)/2;

            if(heap[parent] < heap[i]){
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                break;
        }
        display();
    }
    void display(){
        for(int x: heap)
        cout<<x<<" ";
        cout<<endl;
    }
};

int main(){
    MaxHeap h;

    h.insert(10);
    h.insert(50);
    h.insert(30);
    h.insert(80);
    h.insert(60);
    h.insert(20);

    return 0;
}