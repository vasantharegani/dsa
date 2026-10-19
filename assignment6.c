#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure for a web page
typedef struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
} Node;

// Global pointers to track the sequence and current position
Node* head = NULL;
Node* tail = NULL;
Node* currentPage = NULL;

// Helper function to create a new page node
Node* createNode(const char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert a new page at the end of the sequence
void insertPage(const char* url) {
    Node* newNode = createNode(url);
    if (!newNode) return;

    if (head == NULL) {
        // Condition: Empty List
        head = tail = currentPage = newNode;
    } else {
        // Condition: Append to the end
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        // Automatically set current page to the newly visited page
        currentPage = newNode;
    }
    printf("Successfully visited: %s\n", url);
}

// 2. Move Forward to the next page
void moveForward() {
    if (currentPage == NULL) {
        printf("No pages visited yet.\n");
        return;
    }
    if (currentPage->next == NULL) {
        printf("End condition reached: You are already at the newest page.\n");
    } else {
        currentPage = currentPage->next;
        printf("Moved forward to: %s\n", currentPage->url);
    }
}

// 3. Move Backward to the previous page
void moveBackward() {
    if (currentPage == NULL) {
        printf("No pages visited yet.\n");
        return;
    }
    if (currentPage->prev == NULL) {
        printf("Beginning condition reached: You are at the first page in history.\n");
    } else {
        currentPage = currentPage->prev;
        printf("Moved backward to: %s\n", currentPage->url);
    }
}

// 4. Delete a specified page by its URL
void deletePage(const char* url) {
    if (head == NULL) {
        printf("History is empty. Nothing to delete.\n");
        return;
    }

    Node* temp = head;
    // Search for the page matching the URL
    while (temp != NULL && strcmp(temp->url, url) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Page '%s' not found in history.\n", url);
        return;
    }

    // Adjust currentPage pointer if the active page is being deleted
    if (temp == currentPage) {
        if (currentPage->next != NULL) {
            currentPage = currentPage->next;
        } else {
            currentPage = currentPage->prev; // Might become NULL if it was the only node
        }
    }

    // Handle structural pointer updates
    if (temp == head && temp == tail) {
        // Case A: Only one node in the list
        head = tail = NULL;
    } else if (temp == head) {
        // Case B: Deleting the head node
        head = head->next;
        head->prev = NULL;
    } else if (temp == tail) {
        // Case C: Deleting the tail node
        tail = tail->prev;
        tail->next = NULL;
    } else {
        // Case D: Deleting a middle node
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Successfully deleted '%s' from history.\n", url);
}

// 5. Display history from First-to-Last (Chronological order)
void displayFirstToLast() {
    if (head == NULL) {
        printf("History is empty.\n");
        return;
    }
    printf("\n--- Web History (First-to-Last) ---\n");
    Node* temp = head;
    while (temp != NULL) {
        if (temp == currentPage) {
            printf("[CURRENT] %s\n", temp->url);
        } else {
            printf("          %s\n", temp->url);
        }
        temp = temp->next;
    }
    printf("------------------------------------\n");
}

// 6. Display history from Last-to-First (Reverse order)
void displayLastToFirst() {
    if (tail == NULL) {
        printf("History is empty.\n");
        return;
    }
    printf("\n--- Web History (Last-to-First) ---\n");
    Node* temp = tail;
    while (temp != NULL) {
        if (temp == currentPage) {
            printf("[CURRENT] %s\n", temp->url);
        } else {
            printf("          %s\n", temp->url);
        }
        temp = temp->prev;
    }
    printf("------------------------------------\n");
}

// Helper function to clean up allocated memory before exiting
void freeList() {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    head = tail = currentPage = NULL;
}

// Main method featuring an interactive console menu
int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n======= BROWSER HISTORY MENU =======\n");
        printf("1. Visit New Page (Insert)\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Specific Page\n");
        printf("5. Display History (First-to-Last)\n");
        printf("6. Display History (Last-to-First)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear trailing newline from buffer

        switch (choice) {
            case 1:
                printf("Enter Web Page URL: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = '\0'; // Remove newline character
                insertPage(url);
                break;
            case 2:
                moveForward();
                break;
            case 3:
                moveBackward();
                break;
            case 4:
                printf("Enter URL to delete: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = '\0';
                deletePage(url);
                break;
            case 5:
                displayFirstToLast();
                break;
            case 6:
                displayLastToFirst();
                break;
            case 7:
                freeList();
                printf("Exiting program. Memory cleared.\n");
                return 0;
            default:
                printf("Invalid choice! Please select between 1 and 7.\n");
        }
    }
    return 0;
}