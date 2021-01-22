#include<stdio.h>

int binarySearch(int arr[], int x, int l, int r) {
    if (l <= r) {
        int mid = l + (r+l)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            binarySearch(arr, x, l, mid-1);
        binarySearch(arr, x, mid+1, r);
    }
    return -1;
}

void main() {
    int arr[100], n, x;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &x);
    int index = binarySearch(arr, x, 0, n-1);
    index != -1 
    ? printf("Element found at index %d\n", index) 
    : printf("Element not found");
}