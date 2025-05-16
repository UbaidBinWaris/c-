#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

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

bool is_safe_state(int n, int m, int Allocation[][MAX_RESOURCES], int Need[][MAX_RESOURCES], int Available[]) {
    bool Finish[MAX_PROCESSES] = {false};
    int Work[MAX_RESOURCES];
    for (int i = 0; i < m; i++) {
        Work[i] = Available[i];
    }

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!Finish[i] && less_than_or_equal(Need[i], Work, m)) {
                add_vectors(Work, Allocation[i], m);
                Finish[i] = true;
                found = true;
                count++;
            }
        }
        if (!found) {
            break; // no process could proceed
        }
    }

    // If all processes are finished, safe state
    for (int i = 0; i < n; i++) {
        if (!Finish[i]) return false;
    }
    return true;
}

int main() {
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int Allocation[MAX_PROCESSES][MAX_RESOURCES];
    int Max[MAX_PROCESSES][MAX_RESOURCES];
    int Need[MAX_PROCESSES][MAX_RESOURCES];
    int Available[MAX_RESOURCES];

    printf("Enter Allocation matrix (%d processes x %d resources):\n", n, m);
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &Allocation[i][j]);
        }
    }

    printf("Enter Maximum Demand matrix (%d processes x %d resources):\n", n, m);
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &Max[i][j]);
        }
    }

    printf("Enter Available resources vector (%d resources):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &Available[i]);
    }

    // Calculate Need matrix = Max - Allocation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    // Check system safe state initially
    if (is_safe_state(n, m, Allocation, Need, Available)) {
        printf("\nSystem is in a safe state.\n");
    } else {
        printf("\nSystem is NOT in a safe state.\n");
        return 0; // no need to proceed further if unsafe initially
    }

    // Additional resource request
    int process_id;
    printf("\nEnter process number (0 to %d) making additional resource request: ", n - 1);
    scanf("%d", &process_id);

    if (process_id < 0 || process_id >= n) {
        printf("Invalid process number.\n");
        return 1;
    }

    int Request[MAX_RESOURCES];
    printf("Enter resource request vector for process P%d:\n", process_id);
    for (int i = 0; i < m; i++) {
        scanf("%d", &Request[i]);
    }

    // Check if Request <= Need
    if (!less_than_or_equal(Request, Need[process_id], m)) {
        printf("Error: Process has exceeded its maximum claim.\n");
        return 1;
    }

    // Check if Request <= Available
    if (!less_than_or_equal(Request, Available, m)) {
        printf("Resources are not available currently. Process must wait.\n");
        return 1;
    }

    // Pretend to allocate requested resources
    subtract_vectors(Available, Request, m);
    add_vectors(Allocation[process_id], Request, m);
    subtract_vectors(Need[process_id], Request, m);

    // Check if new state is safe
    if (is_safe_state(n, m, Allocation, Need, Available)) {
        printf("Request can be safely granted.\n");
    } else {
        // Rollback since unsafe
        add_vectors(Available, Request, m);
        subtract_vectors(Allocation[process_id], Request, m);
        add_vectors(Need[process_id], Request, m);
        printf("Request cannot be granted as it leads to unsafe state.\n");
    }

    return 0;
}
