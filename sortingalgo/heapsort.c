#include<stdio.h>

/*------------------- function to swap the integers -------------*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*--------------- function to heapify the array ------------------*/
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }

}

/*-------------------- headSort function --------------------------*/
void heapSort(int arr[], int n) {
    // build max heap 
    for (int i=n/2-1; i>=0; i--) 
        heapify(arr, n, i);
    
    // heap sort 
    for (int i=n-1; i>=0; i--) {
        swap(&arr[0], &arr[i]);
        // heapify the root to get largest element at the root again 
        heapify(arr, i, 0);
    }
}

/*----------------------- main function ---------------------------*/
int main() {
    int arr[100], n;

    // scanning array
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // printing sorted array
    printf("Sorted Array\n");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}