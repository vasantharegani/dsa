#include <stdio.h>

// Function to print the current state of the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, shifts = 0;

    // Input the number of marks
    printf("Enter the number of students (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    int arr[n];

    // Input the marks
    printf("Enter %d marks:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nInitial Marks: ");
    printArray(arr, n);
    printf("-----------------------------\n");

    // Insertion Sort algorithm
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            shifts++; // Increment shift counter
            j--;
        }
        arr[j + 1] = key;

        // Display the array state after each pass
        printf("After Pass %d: ", i);
        printArray(arr, n);
    }

    printf("-----------------------------\n");
    // Display the final sorted list and shift count
    printf("Final Sorted Marks: ");
    printArray(arr, n);
    printf("Total number of element shifts: %d\n", shifts);

    return 0;
}