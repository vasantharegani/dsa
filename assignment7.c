#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a unique value into the BST
struct Node* insert(struct Node* root, int value) {
    // If the tree/subtree is empty, return a new node
    if (root == NULL) {
        return createNode(value);
    }
    
    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    // Duplicate values are ignored since IDs are unique
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int key) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }
    
    // Key is smaller than root's data
    if (key < root->data) {
        return search(root->left, key);
    }
    
    // Key is greater than root's data
    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int n, value, searchKey;

    printf("Enter the number of identification numbers to insert: ");
    if (scanf("%d", &n) != 1) return 1;

    printf("Enter %d unique integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Displaying Traversals
    printf("\n--- BST Traversal Outputs ---\n");
    printf("Inorder Traversal:   ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal:  ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n\n");

    // Searching a value
    printf("Enter an ID to search for: ");
    scanf("%d", &searchKey);

    struct Node* found = search(root, searchKey);
    if (found != NULL) {
        printf("Result: Value %d EXISTS in the system.\n", searchKey);
    } else {
        printf("Result: Value %d DOES NOT EXIST in the system.\n", searchKey);
    }

    return 0;
}