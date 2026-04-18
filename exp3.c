#include <stdio.h>
#include <stdlib.h>
// function to sort items in descending order
void sortDescending(int items[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i] < items[j]) {
                int temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}
// 1. FIRST FIT
int firstFit(int items[], int n, int capacity) {
    int res = 0;
    int bin_rem[n];
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < res; j++) {
            if (bin_rem[j] >= items[i]) {
                bin_rem[j] -= items[i];
                break;
            }
        }
        if (j == res) {
            bin_rem[res] = capacity - items[i];
            res++;
        }
    }
    return res;
}
// 2. BEST FIT
int bestFit(int items[], int n, int capacity) {
    int res = 0;
    int bin_rem[n];
    int i, j;
    for (i = 0; i < n; i++) {
        int min_space = capacity + 1, best_bin = -1;
        for (j = 0; j < res; j++) {
            if (bin_rem[j] >= items[i] && bin_rem[j] - items[i] < min_space) {
                best_bin = j;
                min_space = bin_rem[j] - items[i];
            }
        }
        if (best_bin == -1) {
            bin_rem[res] = capacity - items[i];
            res++;
        } else {
            bin_rem[best_bin] -= items[i];
        }
    }
    return res;
}
int main() {
    int n, capacity, i;
    printf("Enter the bin capacity: ");
    scanf("%d", &capacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int items[n]; 

    printf("Enter the weights of the %d items:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }
    printf("First Fit: %d bins\n", firstFit(items, n, capacity));
    printf("Best Fit:  %d bins\n", bestFit(items, n, capacity));
    sortDescending(items, n);
    printf("First Fit Decreasing:  %d bins\n", firstFit(items, n, capacity));
    printf("Best Fit Decreasing:  %d bins\n", bestFit(items, n, capacity));

    return 0;
}

