#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 6;
    float *prices = (float *)malloc(n * sizeof(float));
    if (prices == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input product prices
    printf("Enter prices for %d products:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Product %d: ", i + 1);
        if (scanf("%f", &prices[i]) != 1) {
            printf("Invalid input.\n");
            free(prices);
            return 1;
        }
    }

    // Calculate average price
    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += prices[i];
    }
    float average = sum / n;
    printf("\nAverage price: %.2f\n", average);

    // Free allocated memory to prevent memory leak
    free(prices);

    return 0;
}
