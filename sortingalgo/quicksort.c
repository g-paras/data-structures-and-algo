#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


int partition(int array[], int low, int high) {
  
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}


void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    int pi = partition(array, low, high);
    
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}


int main() {
  int arr[100], n;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  // sorting array 
  quickSort(arr, 0, n-1);
  // printing array 
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}