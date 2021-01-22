#include<stdio.h>

int main() {
    int arr[100], n, temp;

    // scanning array 
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // bubble sort login 
    for (int i=0; i<=n-1; i++) {
        for (int j=0; j<=n-i-2; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // printing sorted array 
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}