#include<stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i=0; i<n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

void main() {
    int arr[100], n, x;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter an element to search: ");
    scanf("%d", &x);
    if (linearSearch(arr, n, x) != -1)
        printf("Element found at index %d\n", linearSearch(arr, n, x));
    else 
        printf("Element not found\n");
}