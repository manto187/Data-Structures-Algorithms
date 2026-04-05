#include<stdio.h>
#include<stdbool.h>
int BinarySearch(int A[], int n, int x, bool searchFirst){
    int low = 0, high = n-1, result=-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(A[mid]==x){
            result = mid;
            if(searchFirst) high = mid-1;
            else low = mid+1;
        }
        else if(x<A[mid]) high = mid-1;
        else low = mid+1;
    }
    return result;
}

int main(){
    int A[] = {1,1,3,3,5,5,5,5,5,9,9,11};
    int x;
    printf("enter a number: ");
    scanf("%d", &x);
    int firstIndex = BinarySearch(A, sizeof(A)/sizeof(A[0]), x, true);
    if(firstIndex == -1){
        printf("count of %d is %d", x,0);

    }
    else{
        int lastIndex = BinarySearch(A, sizeof(A)/sizeof(A[0]), x, false);
        printf("count of %d is %d", x, lastIndex-firstIndex+1); 
    }
    return 0;
}