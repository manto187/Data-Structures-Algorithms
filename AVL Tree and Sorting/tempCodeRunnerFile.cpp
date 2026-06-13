#include<iostream>
using namespace std;

int main(){
    int arr[] = {8,4,1,9,3};
    int n = 5;

    for(int i=0; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    cout<<"sorted array: \n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}