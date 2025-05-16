#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100

int main() {
    int initial_size = 100;
    int reduced_size = 10;

    // Allocate memory for 100 file name pointers, initialized to NULL
    char **file_names = (char **)calloc(initial_size, sizeof(char *));
    if (file_names == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Simulate name input for first 30 entries
    printf("Enter 30 file names:\n");
    for (int i = 0; i < reduced_size; i++) {
        char buffer[MAX_NAME_LEN];
        printf("File %d: ", i + 1);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error reading input.\n");
            break;
        }
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = 0;

        // Allocate exact memory for this file name and copy it
        file_names[i] = (char *)malloc(strlen(buffer) + 1);
        if (file_names[i] == NULL) {
            printf("Memory allocation failed for file name.\n");
            break;
        }
        strcpy(file_names[i], buffer);
    }

    // Shrink memory to hold only 30 entries
    char **temp = (char **)realloc(file_names, reduced_size * sizeof(char *));
    if (temp == NULL) {
        printf("Reallocation failed. Keeping original allocation.\n");
        // We can continue with the original pointer, so just ignore realloc failure
    } else {
        file_names = temp;
    }

    // Display the list of file names
    printf("\nFile names stored:\n");
    for (int i = 0; i < reduced_size; i++) {
        if (file_names[i] != NULL)
            printf("%d. %s\n", i + 1, file_names[i]);
        else
            printf("%d. [Empty]\n", i + 1);
    }

    // Free allocated strings
    for (int i = 0; i < reduced_size; i++) {
        free(file_names[i]);
    }

    // Free the array of pointers
    free(file_names);

    return 0;
}
