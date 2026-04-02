#include<stdio.h>
int BinarySearch(int A[], int n, int x){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(x==A[mid]) return mid;
        else if(x<A[mid]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}
int main(){
    int A[] = {2,4,5,7,13,14,23};
    printf("enter a number: ");
    int x; scanf("%d", &x);
    int index = BinarySearch(A, 8, x);
    if(index!=-1) printf("number is %d is at index %d, ", x,index);
    else printf("number %d not found", x);
}