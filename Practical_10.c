/*
Implement program for solution of Making Change problem using greedy design technique.*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        int max_index = i;
        for (int j = i; j >= 0; j--) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        if (i != max_index) {
            swap(&arr[i], &arr[max_index]);
        }
    }
}

void main(){
    int n;
    printf("Enter number of denominations : ");
    scanf("%d",&n);


    int d[n];
    int A;
    printf("Denominations : ");
    for(int i=0;i<n;i++){
        scanf("%d",&d[i]);
    }
    printf("Enter Total Amount : ");
    scanf("%d",&A);

    selectionSort(d,n);

    int total = 0;
    int i = n-1;
    int k = 0;
    int *changes = (int *)malloc(n * sizeof(int));
    
    while(total!=A && i>=0){
        if(d[i] + total<=A){
            total+=d[i];
            changes[k]=d[i]; 
            k++;

            if (k >= n) {
                n *= 2; // Double the size
                changes = (int *)realloc(changes, n * sizeof(int));

                if (changes == NULL) {
                    printf("Memory reallocation failed.\n");
                    return;
                }
            }
        }
        else{
            i--;
        }
        if(total>A){
            printf("Not Possible!!\n");
            break;
        }
        if (total == A) {
            printf("Changes: ");
            for (int j = 0; j < k; j++) {
                printf("%d ", changes[j]);
            }
            printf("\n");
            free(changes);
            break;
        }
    }
    // printf("Not Possible!!\n");
}