#include <stdio.h>
#include <stdlib.h>
struct Item {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};
int compareItems(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->profit_weight_ratio - item1->profit_weight_ratio) > 0 ? 1 : -1;
}
int main() {
    int n;
    int i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    for (i = 0; i < n; i++) {
        items[i].item_id = i + 1;
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    double capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%lf", &capacity);
   qsort(items, n, sizeof(struct Item), compareItems);

    double maxProfit = 0.0;
    double currentWeight = 0.0;

    printf("\nItem No\tProfit\tWeight\tAmount to be taken\n");

    for (i = 0; i < n; i++) {
        double taken = (currentWeight + items[i].item_weight <= capacity) ? 1.0 : (capacity - currentWeight) / items[i].item_weight;
        double profit = taken * items[i].item_profit;
        currentWeight += taken * items[i].item_weight;
        maxProfit += profit;
        printf("%d\t%.6lf\t%.6lf\t%.6lf\n", items[i].item_id, items[i].item_profit, items[i].item_weight, taken);
    }
    
    printf("Maximum profit: %.6lf\n", maxProfit);

    return 0;
}
