#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;

    int comparisons = 0;
    int shifts = 0;

    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0){
            comparisons++;

            if(arr[j]>key){
                arr[j+1] = arr[j];
                shifts++;
                j--;
            }
            else
                break;
        }
        arr[j+1] = key;
    }
    cout<<"comparisons: "<<comparisons<<endl;
    cout<<"shifts: "<<shifts<<endl;
}