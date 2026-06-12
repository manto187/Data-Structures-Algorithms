#include<iostream>
#include<vector>
using namespace std;

class MinHeap{
public:
    vector<int> heap;

    void insert(int value){
        heap.push_back(value);

        int i = heap.size()-1;

        while(i>0){
            int parent = (i-1)/2;

            if(heap[parent] > heap[i]){
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                break;
        }
        display();
    }
    void display(){
        for(int x:heap)
            cout<<x<<" ";
        cout<<endl;
    }
};
int main(){
    MinHeap h;

    h.insert(45);
    h.insert(20);
    h.insert(35);
    h.insert(10);
    h.insert(25);
    h.insert(15);

    return 0;
}