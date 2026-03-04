#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Sort by Maximum Profit 
void sortByProfit(struct Item arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j].profit < arr[j+1].profit) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Sort by Maximum Weight 
void sortByWeight(struct Item arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j].weight < arr[j+1].weight) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Sort by Profit/Weight Ratio 
void sortByRatio(struct Item arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j].ratio < arr[j+1].ratio) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void knapsack(struct Item arr[], int n, int capacity) {
    float totalProfit = 0.0;

    for(int i=0;i<n;i++) {

        if(arr[i].weight <= capacity) {
            capacity -= arr[i].weight;
            totalProfit += arr[i].profit;
        }
        else {
            totalProfit += arr[i].profit * ((float)capacity / arr[i].weight);
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);
}

int main() {

    int n, capacity;
// comment
    printf("Enter number of items: ");
    scanf("%d",&n);

    struct Item arr[n];

    printf("Enter weight and profit of each item:\n");

    for(int i=0;i<n;i++) {
        scanf("%d %d",&arr[i].weight,&arr[i].profit);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d",&capacity);

    struct Item temp[n];

    /* Case 1: Maximum Profit */
    for(int i=0;i<n;i++) temp[i] = arr[i];
    sortByProfit(temp,n);
    printf("\nCase 1: Selection by Maximum Profit\n");
    knapsack(temp,n,capacity);

    /* Case 2: Maximum Weight */
    for(int i=0;i<n;i++) temp[i] = arr[i];
    sortByWeight(temp,n);
    printf("\nCase 2: Selection by Maximum Weight\n");
    knapsack(temp,n,capacity);

    /* Case 3: Profit/Weight Ratio */
    for(int i=0;i<n;i++) temp[i] = arr[i];
    sortByRatio(temp,n);
    printf("\nCase 3: Selection by Profit/Weight Ratio\n");
    knapsack(temp,n,capacity);

    return 0;
}