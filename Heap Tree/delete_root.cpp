#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
public:
    vector<int> heap = {80,60,30,10,50,20};

    void deleteRoot() {

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;

        while(true) {

            int left = 2*i+1;
            int right = 2*i+2;
            int largest = i;

            if(left < heap.size() &&
               heap[left] > heap[largest])
                largest = left;

            if(right < heap.size() &&
               heap[right] > heap[largest])
                largest = right;

            if(largest != i) {

                cout<<"Swap "
                    <<heap[i]
                    <<" and "
                    <<heap[largest]
                    <<endl;

                swap(heap[i], heap[largest]);
                i = largest;
            }
            else
                break;
        }
    }

    void display() {
        for(int x : heap)
            cout<<x<<" ";
    }
};

int main() {

    MaxHeap h;

    h.deleteRoot();

    h.display();

    return 0;
}