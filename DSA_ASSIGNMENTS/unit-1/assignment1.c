#include <stdio.h>

int main() {
    int n, target, i;
    int comparisons = 0;
    int low, high, mid;
    int found = 0;

    // Input the number of employees
    printf("Enter the number of employees (n): ");
    scanf("%d", &n);

    int arr[n];

    // Input the employee IDs (must be entered in ascending order)
    printf("Enter %d employee IDs in ascending order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target ID to search for
    printf("Enter the employee ID to search for: ");
    scanf("%d", &target);

    // Binary Search Logic
    low = 0;
    high = n - 1;

    while (low <= high) {
        comparisons++; // Increment comparison count for this step
        mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            printf("\nEmployee ID %d found at position (index): %d\n", target, mid);
            found = 1;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("\nEmployee ID %d is absent from the records.\n", target);
    }

    // Display total comparisons made
    printf("Total number of comparisons made: %d\n", comparisons);

    return 0;
}