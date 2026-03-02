#include<stdio.h>
int main(){
    //task 2
    int x = 5;
    int *p = &x;
    *p = *p+7;
    printf("%d", x);

    // task 3
     int x = 4;
     int *p = &x;
     int *q = p;
     *q = 9;
     printf("%d %d", x, *p);
}