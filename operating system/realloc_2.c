#include <stdio.h>
#include <stdlib.h>

int main() {
    float *temperatures = NULL;  // Pointer to store temperatures
    int count = 0;               // Number of readings stored
    float input;

    printf("Enter temperature readings (enter -1 to stop):\n");

    while (1) {
        printf("Reading %d: ", count + 1);
        if (scanf("%f", &input) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        if (input == -1.0f) {
            // Stop input
            break;
        }

        // Reallocate memory for one more reading
        float *temp_ptr = realloc(temperatures, (count + 1) * sizeof(float));
        if (temp_ptr == NULL) {
            printf("Memory allocation failed.\n");
            free(temperatures);
            return 1;
        }
        temperatures = temp_ptr;

        // Store the new reading
        temperatures[count] = input;
        count++;
    }

    // Display all stored readings
    printf("\nStored temperature readings:\n");
    for (int i = 0; i < count; i++) {
        printf("Reading %d: %.2f\n", i + 1, temperatures[i]);
    }

    // Free allocated memory
    free(temperatures);

    return 0;
}
