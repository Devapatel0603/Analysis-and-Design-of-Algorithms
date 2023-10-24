#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;
char queue[MAX_SIZE];
int front = -1;
int rear = -1;
struct Edge
{
    char S;
    char D;
};
bool isStackEmpty() { return top == -1; }
void push(char item)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = item;
}
char pop()
{
    if (isStackEmpty())
    {
        printf("Stack underflow\n");
        return '\0'; // Error code
    }
    return stack[top--];
}
bool isQueueEmpty() { return front == -1 && rear == -1; }
void enqueue(char item)
{
    if (isQueueEmpty())
    {
        front = 0;
        rear = 0;
        queue[rear] = item;
        return;
    }
    if ((rear + 1) % MAX_SIZE == front)
    {
        printf("Queue is full\n");
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = item;
}
char dequeue()
{
    if (isQueueEmpty())
    {
        printf("Queue is empty\n");
        return '\0'; // Error code
    }
    if (front == rear)
    {
        int item = queue[front];
        front = rear = -1;
        return item;
    }
    int item = queue[front];
    front = (front + 1) % MAX_SIZE;
    return item;
}
// Assuming 'a' is the lowest character
int charToIndex(char c) { return c - 'a'; }
char IndexToChar(int i) { return i + 'a'; }
bool check_visited(bool v[], char n) { return v[charToIndex(n)]; }
void printStack()
{
    if (isStackEmpty())
    {
        printf("Stack : -\n");
        return;
    }
    printf("Stack : ");
    for (int i = 0; i <= top; i++)
    {
        printf("%c ", stack[i]);
    }
    printf("\n");
}
void printQueue()
{
    if (isQueueEmpty())
    {
        printf("Queue : -\n");
        return;
    }
    printf("Queue : ");
    for (int i = front; i <= rear; i++)
    {
        printf("%c ", queue[i]);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("How many nodes are there? : ");
    scanf("%d", &n);
    int e;
    printf("How many edges are there? : ");
    scanf("%d", &e);
    bool graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = false;
        }
    }
    struct Edge edges[e];
    for (int i = 0; i < e; i++)
    {
        printf("Edge %d :\n", i + 1);
        printf("Source : ");
        scanf(" %c", &edges[i].S);
        printf("Destination : ");
        scanf(" %c", &edges[i].D);
        int srcIndex = charToIndex(edges[i].S);
        int destIndex = charToIndex(edges[i].D);
        graph[srcIndex][destIndex] = true;
        graph[destIndex][srcIndex] = true;
    }
    char S;
    printf("\nStarting node : ");
    scanf(" %c", &S);
    // DFS
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    char dfs[n];
    push(S);
    visited[charToIndex(S)] = true;
    int visited_n = 1;
    int d = 0;
    printStack();
    while (!isStackEmpty())
    {
        char t = pop();
        dfs[d] = t;
        d++;
        for (int i = 0; i < n; i++)
        {
            char node = charToIndex(t);
            if (graph[node][i] && !check_visited(visited, IndexToChar(i)))
            {
                push(IndexToChar(i));
                visited[i] = true;
            }
        }
        printStack();
    }
    printf("DFS Traversal: ");
    for (int i = 0; i < d; i++)
    {
        printf("%c ", dfs[i]);
    }
    printf("\n\n");
    // BFS
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    char bfs[n];
    enqueue(S);
    visited[charToIndex(S)] = true;
    int b = 0;
    printQueue();
    while (!isQueueEmpty())
    {
        char t = dequeue();
        bfs[b] = t;
        b++;
        for (int i = 0; i < n; i++)
        {
            char node = charToIndex(t);
            if (graph[node][i] && !check_visited(visited, IndexToChar(i)))
            {
                enqueue(IndexToChar(i));
                visited[i] = true;
            }
        }
        printQueue();
    }
    printf("BFS Traversal: ");
    for (int i = 0; i < b; i++)
    {
        printf("%c ", bfs[i]);
    }
    printf("\n");
    return 0;
}