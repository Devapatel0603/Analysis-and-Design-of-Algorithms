/*
Implement program for Kruskal's algorithm to find minimum spanning tree.*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Edge{
    char S;
    char D;
    int W;
};

int compareByW(const void *a, const void *b) {
    const struct Edge *edgeA = (const struct Edge *)a;
    const struct Edge *edgeB = (const struct Edge *)b;
    if (edgeA->W < edgeB->W) return -1;
    if (edgeA->W > edgeB->W) return 1;
    return 0;
}

void main(){
    int n;
    printf("How many nodes are there?\n");
    scanf("%d",&n);

    
    int e;
    printf("How many edges are there?\n");
    scanf("%d",&e);
    
    struct Edge edges[e];
    for(int i=0;i<e;i++){
        printf("Edge %d..\n",i+1);
        printf("Source : ");
        scanf(" %c",&edges[i].S);
        printf("Destination : ");
        scanf(" %c",&edges[i].D);
        printf("Weight : ");
        scanf("%d",&edges[i].W);
    }

    // Sort the edge by weight in ascending order
    qsort(edges, e, sizeof(struct Edge), compareByW);

    struct Edge selected_e[n-1];
    int mst = 0;
    // int visited_n = 0;
    int sel_e = 0;

    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    
    for(int i=0;i<e;i++){
        if (sel_e == n-1) {
            break;  
        }
        char src = edges[i].S;
        char dest = edges[i].D;
        
        int src_parent = parent[src - 'a'];
        int dest_parent = parent[dest - 'a'];
    
        if (src_parent != dest_parent) {
            // If the source and destination have different parents, add the edge to MST
            selected_e[sel_e++] = edges[i];
            mst += edges[i].W;
    
            // Merge the sets by making the parent of the source the same as the destination
            for (int j = 0; j < n; j++) {
                if (parent[j] == src_parent) {
                    parent[j] = dest_parent;
                }
            }
    }

    }
    printf("Selected edges in MST:\n");
    printf("Sorce\tDest\tWeight\n");
    for(int i=0;i<n-1;i++){
        printf("%c\t%c\t%d\n",selected_e[i].S,selected_e[i].D,selected_e[i].W);
    }
    printf("The cost of MST : %d\n",mst);
}