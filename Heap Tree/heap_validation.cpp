#include <iostream>
using namespace std;

bool isHeap(int arr[], int n)
{
    for(int i=0;i<=(n-2)/2;i++)
    {
        if(2*i+1<n && arr[i]<arr[2*i+1])
            return false;

        if(2*i+2<n && arr[i]<arr[2*i+2])
            return false;
    }

    return true;
}

int main()
{
    int arr1[] = {100,80,90,30,40,50,60};
    int arr2[] = {100,120,90,30,40,50,60};

    cout<<isHeap(arr1,7)<<endl;
    cout<<isHeap(arr2,7)<<endl;

    return 0;
}