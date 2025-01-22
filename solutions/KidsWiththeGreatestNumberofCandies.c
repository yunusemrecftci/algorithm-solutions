#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findMax(int candies[], int n) {
    int max = candies[0];
    for (int i = 1; i < n; i++) {
        if (candies[i] > max) {
            max = candies[i];
        }
    }
    return max;
}
bool* kidsWithCandies(int candies[], int n, int extraCandies, int* returnSize) {
    bool* result = (bool*)malloc(n * sizeof(bool));
    if (!result) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    int maxCandies = findMax(candies, n);

    for (int i = 0; i < n; i++) {
        result[i] = (candies[i] + extraCandies >= maxCandies);
    }

    *returnSize = n;
    return result;
}


