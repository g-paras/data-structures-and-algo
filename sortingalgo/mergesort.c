#include<stdio.h>

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid-l+1;
    int n2 = r-mid;

    int a[n1], b[n2];

    for (int i=0; i<n1; i++) {
        a[i] = arr[l+i];
    }
    for (int i=0; i<n2; i++) {
        b[i] = arr[mid+1+i];
    }

    int i, j, k;
    i = j = 0;
    k = l;
    
    while (i<n1 && j<n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            k++; i++;
        }
        else {
            arr[k] = b[j];
            k++; j++;
        }
    }

    while (i<n1) {
        arr[k] = a[i];
        k++; i++;
    }

    while (j<n2) {
        arr[k] = b[j];
        k++; j++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
 
        merge(arr, l, mid, r);
    }
}

void main() {
    int arr[100], n;
    scanf("%d", &n);
    // scanning array 
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    // sorting array
    mergeSort(arr, 0, n-1);
    // printing sorted array
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}