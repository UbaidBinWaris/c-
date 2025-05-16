#include <stdio.h>
#include <stdlib.h>

int main() {
    int initial_days = 7;
    int reduced_days = 4;
    
    // Allocate memory for 7 float expenses initialized to 0.0
    float *expenses = (float *)calloc(initial_days, sizeof(float));
    if (expenses == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input expenses for 7 days
    printf("Enter expenses for %d days:\n", initial_days);
    for (int i = 0; i < initial_days; i++) {
        printf("Day %d: ", i + 1);
        if (scanf("%f", &expenses[i]) != 1) {
            printf("Invalid input.\n");
            free(expenses);
            return 1;
        }
    }

    // Shrink memory to hold only 4 expenses
    float *temp = (float *)realloc(expenses, reduced_days * sizeof(float));
    if (temp == NULL) {
        printf("Reallocation failed. Keeping original data.\n");
        // Continue with original expenses pointer if realloc fails
    } else {
        expenses = temp;
    }

    // Print updated expenses
    printf("\nUpdated expenses for %d days:\n", reduced_days);
    for (int i = 0; i < reduced_days; i++) {
        printf("Day %d: %.2f\n", i + 1, expenses[i]);
    }

    // Free allocated memory
    free(expenses);

    return 0;
}
