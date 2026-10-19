#include <stdio.h>
#define SIZE 5 // Fixed size of the request buffer

int queue[SIZE];
int front = -1;
int rear = -1;

// Check if the queue is full (Overflow condition)
int isFull() {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        return 1;
    }
    return 0;
}

// Check if the queue is empty (Underflow condition)
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Insertion operation (Enqueue)
void insert(int requestID) {
    if (isFull()) {
        printf(" Buffer Overflow! Cannot add request %d.\n", requestID);
        return;
    }
    
    // First element insertion
    if (front == -1) {
        front = 0;
    }
    
    // Circular increment of rear
    rear = (rear + 1) % SIZE;
    queue[rear] = requestID;
    printf("Inserted request %d at index [%d]\n", requestID, rear);
}

// Deletion operation (Dequeue)
void delete() {
    if (isEmpty()) {
        printf(" Buffer Underflow! No requests to process.\n");
        return;
    }
    
    int processedRequest = queue[front];
    printf(" Processed and removed request %d from index [%d] (This slot is now free!)\n", processedRequest, front);
    
    // Queue becomes empty after this deletion
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        // Circular increment of front
        front = (front + 1) % SIZE;
    }
}

// Display operation
void display() {
    if (isEmpty()) {
        printf("Buffer Status: [ Empty ]\n\n");
        return;
    }
    
    printf("Buffer Status (Front to Rear): ");
    int i = front;
    while (1) {
        printf("[%d: Req %d] ", i, queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n\n");
}

int main() {
    printf("--- SERVICE CENTRE REQUEST BUFFER (Size = %d) ---\n\n", SIZE);

    insert(101);
    insert(102);
    insert(103);
    insert(104);
    insert(105);
    display();

    // Try inserting one more to demonstrate Overflow
    insert(106);
    printf("\n");

    printf("Deleting the first two requests...\n");
    delete();
    delete();
    display();

    // 3. Demonstrate Circular Reuse
    printf("Inserting new requests to  position reuse...\n");
    insert(106); // Should reuse index 0
    insert(107); // Should reuse index 1
    display();

    // Try inserting again to show it is full again
    insert(108);

    return 0;
}