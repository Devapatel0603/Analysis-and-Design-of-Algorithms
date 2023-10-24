/*Implement program to solve Knapsack problem using dynamic programming.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int* find_items(int n,int W,int V[][W+1],int w[]){
    int* items = (int*)malloc(n * sizeof(int));
    if (items == NULL) {
        printf("Memory allocation failed.");
        return NULL;
    }

    int i=n,j=W;
    int k=0;
    while(i>0 && j>0){
        if(V[i][j]!=V[i-1][j]){
            items[k] = i;
            k++;
            j-=w[i-1];
            i-=1;
        }
        else{
            i-=1;
        }
    }
    int* result = (int*)malloc(k * sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed.");
        free(items);
        return NULL;
    }

    for (int m = 0; m < k; m++) {
        result[m] = items[k - 1 - m];
    }

    free(items);
    return result;

}

void main(){
    int n;
    printf("Enter number of items : ");
    scanf("%d",&n);

    int w[n],v[n],W;
    for(int i=0;i<n;i++){
        printf("Weight of item %d : ",i+1);
        scanf("%d",&w[i]);
    }
    
    for(int i=0;i<n;i++){
        printf("Value of item %d: ",i+1);
        scanf("%d",&v[i]);
    }
    printf("Capacity : ");
    scanf("%d",&W);

    int V[n+1][W+1];

    for(int i=0;i<=n;i++){
        V[i][0]=0;
    }
    for(int i=0;i<=W;i++){
        V[0][i]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(i==1 && w[i-1]>j){
                V[i][j] = 0;
            }
            else if(i==1){
                V[i][j] = v[i-1];
            }
            else if(w[i-1]>j){
                V[i][j] = V[i-1][j];
            }
            else{
                if(j-w[i-1] < 0){
                    V[i][j] = V[i-1][j];
                }
                else{
                    V[i][j] = max(V[i-1][j],v[i-1] + V[i-1][j-w[i-1]]);
                }
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            printf("%d ",V[i][j]);
        }
        printf("\n");
    }

    int* ans = find_items(n, W, V, w);
    if (ans != NULL) {
        printf("Used denominations: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
        free(ans);
    } else {
        printf("Failed to find used denominations.");
    }
}