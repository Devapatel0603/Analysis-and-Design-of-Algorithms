/*Implement program for solution of fractional Knapsack problem using greedy design technique*/
#include <stdio.h>
#include <stdlib.h>

struct Item {
    int n;
    float value;
    float weight;
    float v_w;
    float ratio;
};

// Comparison function for qsort
int compareByVW(const void *a, const void *b) {
    const struct Item *itemA = (const struct Item *)a;
    const struct Item *itemB = (const struct Item *)b;
    if (itemA->v_w < itemB->v_w) return 1;
    if (itemA->v_w > itemB->v_w) return -1;
    return 0;
}

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int C;
    printf("Capacity : ");
    scanf("%d",&C);

    struct Item items[n];

    for (int i = 0; i < n; i++) {
        items[i].n = i + 1;
        printf("Item %d:\n", i + 1);
        printf("Value: ");
        scanf("%f", &items[i].value);
        printf("Weight: ");
        scanf("%f", &items[i].weight);

        items[i].v_w = items[i].value / items[i].weight;
    }

    // Sort the items by v_w in descending order
    qsort(items, n, sizeof(struct Item), compareByVW);

    // printf("Items sorted by v_w (value-to-weight ratio):\n");
    // for (int i = 0; i < n; i++) {
    //     printf("Item %d - Value: %.2f, Weight: %.2f, v_w: %.2f\n", items[i].n, items[i].value, items[i].weight, items[i].v_w);
    // }

    struct Item knapsack[n];
    int itemCount = 0;

    int W = 0;
    int i = 0;
    float ans = 0;
    while (W < C && i < n) {
        if (W + items[i].weight <= C) {
            // Add the whole item to the knapsack
            knapsack[itemCount] = items[i];
            knapsack[itemCount].ratio = 1;
            W += items[i].weight;
            ans += items[i].value;
            itemCount++;
        } else {
            // Add a fraction of the item to the knapsack
            float remain = C - W;
            float m = remain / items[i].weight;
            knapsack[itemCount] = items[i];
            knapsack[itemCount].ratio = m;
            knapsack[itemCount].weight = items[i].weight;
            knapsack[itemCount].value = items[i].value;
            W += items[i].weight * m;
            ans += knapsack[itemCount].value;
            itemCount++;
        }
        i++;
    }

    printf("Items in the knapsack (Item, Value, Weight):\n");
    for (int j = 0; j < itemCount; j++) {
        printf("Item %d - Value: %.2f, Weight: %.2f. Ratio: %.2f\n", knapsack[j].n, knapsack[j].value, knapsack[j].weight,knapsack[j].ratio);
    }

    printf("Value(Greedy): %.2f\n", ans);

    return 0;
}