#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

void print_vector(int vec[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

bool less_than_or_equal(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] > b[i]) return false;
    }
    return true;
}

void add_vectors(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] += b[i];
    }
}

void subtract_vectors(int a[], int b[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] -= b[i];
    }
}

void deadlock_detection(int n, int m, int Allocation[][MAX_RESOURCES], int Request[][MAX_RESOURCES], int Available[], bool deadlocked[], int *deadlock_count) {
    int Work[MAX_RESOURCES];
    bool Finish[MAX_PROCESSES] = { false };
    for (int i = 0; i < m; i++) {
        Work[i] = Available[i];
    }

    bool progress;
    do {
        progress = false;
        for (int i = 0; i < n; i++) {
            if (!Finish[i] && less_than_or_equal(Request[i], Work, m)) {
                add_vectors(Work, Allocation[i], m);
                Finish[i] = true;
                progress = true;
            }
        }
    } while (progress);

    *deadlock_count = 0;
    for (int i = 0; i < n; i++) {
        if (!Finish[i]) {
            deadlocked[i] = true;
            (*deadlock_count)++;
        } else {
            deadlocked[i] = false;
        }
    }
}

void deadlock_recovery(int n, int m, int Allocation[][MAX_RESOURCES], int Request[][MAX_RESOURCES], int Available[], bool deadlocked[], int *deadlock_count) {
    while (*deadlock_count > 0) {
        printf("\nDeadlocked processes detected: ");
        for (int i = 0; i < n; i++) {
            if (deadlocked[i]) {
                printf("P%d ", i);
            }
        }
        printf("\n");

        // Terminate one deadlocked process - here we pick the first one found
        int victim = -1;
        for (int i = 0; i < n; i++) {
            if (deadlocked[i]) {
                victim = i;
                break;
            }
        }

        if (victim == -1) {
            printf("No victim found for recovery.\n");
            break;
        }

        printf("Terminating process P%d to recover from deadlock...\n", victim);

        // Release resources allocated to victim
        add_vectors(Available, Allocation[victim], m);

        // Set Allocation and Request of victim to zero to simulate termination
        for (int j = 0; j < m; j++) {
            Allocation[victim][j] = 0;
            Request[victim][j] = 0;
        }

        // Re-run deadlock detection after recovery
        deadlock_detection(n, m, Allocation, Request, Available, deadlocked, deadlock_count);
    }

    if (*deadlock_count == 0) {
        printf("\nDeadlock resolved after recovery.\n");
    }
}

int main() {
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int Allocation[MAX_PROCESSES][MAX_RESOURCES];
    int Request[MAX_PROCESSES][MAX_RESOURCES];
    int Available[MAX_RESOURCES];
    bool deadlocked[MAX_PROCESSES];

    printf("Enter Allocation matrix (%d processes x %d resources):\n", n, m);
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("Enter Request matrix (%d processes x %d resources):\n", n, m);
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &Request[i][j]);
        }
    }

    printf("Enter Available resources vector (%d resources):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &Available[i]);
    }

    int deadlock_count = 0;

    deadlock_detection(n, m, Allocation, Request, Available, deadlocked, &deadlock_count);

    if (deadlock_count == 0) {
        printf("\nNo deadlock detected.\n");
    } else {
        printf("\nDeadlock detected in processes: ");
        for (int i = 0; i < n; i++) {
            if (deadlocked[i]) {
                printf("P%d ", i);
            }
        }
        printf("\n");

        deadlock_recovery(n, m, Allocation, Request, Available, deadlocked, &deadlock_count);
    }

    return 0;
}
