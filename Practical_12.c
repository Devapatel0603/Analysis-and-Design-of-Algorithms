#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct Edge {
    char S;
    char D;
    int W;
};

int charToIndex(char c) {
    // Assuming 'a' is the lowest character
    return c - 'a';
}

bool check_visited(char v[], char n, int vn) {
    for (int i = 0; i < vn; i++) {
        if (v[i] == n) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    printf("How many nodes are there? : ");
    scanf("%d", &n);

    int e;
    printf("How many edges are there? : ");
    scanf("%d", &e);

    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    struct Edge edges[e];
    for (int i = 0; i < e; i++) {
        printf("Edge %d :\n", i + 1);
        printf("Source : ");
        scanf(" %c", &edges[i].S);
        printf("Destination : ");
        scanf(" %c", &edges[i].D);
        printf("Weight : ");
        scanf("%d", &edges[i].W);

        int srcIndex = charToIndex(edges[i].S);
        int destIndex = charToIndex(edges[i].D);

        graph[srcIndex][destIndex] = edges[i].W;
        graph[destIndex][srcIndex] = edges[i].W;
    }

    char S;
    printf("\nStarting node : ");
    scanf(" %c", &S);

    char v[n];
    for (int i = 0; i < n; i++) {
        v[i] = '\0';
    }

    struct Edge selected_e[n - 1];
    int mst = 0;
    int visited_n = 0;
    int sel_e = 0;

    char node_pool[n];
    node_pool[0] = S;
    visited_n = 1;

    while (visited_n != n) {
        struct Edge e;
        e.W = INT_MAX;
        for (int i = 0; i < visited_n; i++) {
            int u = charToIndex(node_pool[i]);
            for (int v = 0; v < n; v++) {
                if (!check_visited(node_pool, 'a' + v, visited_n) && graph[u][v] < e.W) {
                    e.W = graph[u][v];
                    e.S = 'a' + u;
                    e.D = 'a' + v;
                }
            }
        }

        // Add the selected node (e.D) to the MST
        node_pool[visited_n] = e.D;
        visited_n++;

        // Store the selected edge in the MST
        selected_e[sel_e] = e;
        sel_e++;

        // Update the total MST weight
        mst += e.W;
    }

    printf("Selected edges in MST:\n");
    printf("Source\tDest\tWeight\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%c\t%c\t%d\n", selected_e[i].S, selected_e[i].D, selected_e[i].W);
    }
    printf("The cost of MST : %d\n", mst);

    return 0;
}