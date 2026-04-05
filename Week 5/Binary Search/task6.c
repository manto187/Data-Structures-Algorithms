#include<stdio.h>
int circularArraySearch(int A[], int n, int x){
    int low=0, high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(x==A[mid]) return mid;
        if(A[mid]<=A[high])
        {
            if(x>A[mid]&&x<=A[high])
            low = mid+1;
            else 
            high = mid-1;
        }
        else
        {
           if(A[low]<=x && x <A[mid])
           high = mid-1;
           else
           low = mid+1;
        }

    }
    return -1;
}

int main(){
    int A[] = {12,14,18,21,3,6,8,9};
    int x;
    printf("enter a number: ");
    scanf("%d", &x);
    int index = circularArraySearch(A, 8, x);
    if(index == -1)
    printf("%d not found in the array", x);
    else
    printf("%d found at index %d", x, index);   
}