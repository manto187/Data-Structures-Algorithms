#include <stdio.h>
int main()
{
    // task 4
    int arr[] = {10, 20, 30, 40};
    int *p = arr;
    printf("%d", *(p + 3));

    // task 5
    int arr[] = {2, 4, 6, 8};
    int *p = arr;
    printf("%d", *p++);

    // task 6
    int arr[] = {2, 4, 6, 8};
    int *p = arr;
    printf("%d", *(++p));

    // task 7

    int arr[] = {1, 3, 5, 7};
    printf("%d", *(arr + 2));

    // task 8
    int x = 10;
    int *p = &x;
    printf("%d", *(p) + 5);
}