#include<stdio.h>
#include<time.h>
int loop(int n){
    long sum = 0;
    for(int i=1;i<=n;i++){
        sum = sum + i;
    }
    return sum;
}
int equation(int n){
    return (n*(n+1))/2;
}
int recursion(int n){
    if(n==1){
        return 1;
    }
    return recursion(n-1)+ n;
}
void main(){
    printf("Enter a number : ");
    int n;
    scanf("%d",&n);
    printf("\n");
    time_t start,end;
    double tloop,tequation,trecursion;

    start = clock();
    long o = loop(n);
    end = clock();
    tloop = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Sum using Loop : %ld\n",o);
    printf("Time for loop : %lf\n",tloop);
    
    start = clock();
    long p = equation(n);
    end = clock();
    tequation = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Sum using Equation : %ld\n",p);
    printf("Time for loop : %lf\n",tequation);

    start = clock();
    long q = recursion(n);
    end = clock();
    trecursion = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Sum using Recursion : %ld\n",q);
    printf("Time for recursion : %lf\n",trecursion);
}
