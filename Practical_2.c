#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void descending_order(int n,int arr[]){
  for(int i = 0 ; i < n ; i++){
    arr[i] = n-i;
  }
}

void random_order(int n,int arr[]){
    for(int i = 0 ; i < n ; i++){
      arr[i] = rand()%n;
    }
}

void ascending_order(int n, int arr[]){
  for(int i = 0 ; i < n ; i++){
    arr[i] = i;
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int array[], int size) {
  for (int step = 0; step < size - 1; ++step) {    
    for (int i = 0; i < size - step - 1; ++i) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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

void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  while (i < n1 && j < n2){
    if (L[i] <= M[j]){
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++){
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}
void time_calculate(time_t start, time_t end){
  double final = ((double)(end-start))/CLOCKS_PER_SEC;
  printf("Time taken : %lf\n",final);
}

int main() {
  int n = 10000;
  printf("Enter the size of the array : \n");
  scanf("%d",&n);
  int arr[n];
  ascending_order(n,arr);
  //random_order(n,arr);
  //descending_order(n,arr);
  time_t start,end;

  start = clock();
  bubbleSort(arr, n);
  end = clock();
  time_calculate(start,end);

  start = clock();
  selectionSort(arr, n);
  end = clock();
  time_calculate(start,end);

  start = clock();
  insertionSort(arr, n);
  end = clock();
  time_calculate(start,end);

  start = clock();
  mergeSort(arr, 0, n);
  end = clock();
  time_calculate(start,end);

  start = clock();
  quickSort(arr, 0, n);
  end = clock();
  time_calculate(start,end);
}

