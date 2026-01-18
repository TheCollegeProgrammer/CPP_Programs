#include <stdio.h>
#include <stdlib.h>

// 1. Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// 2. Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 3. Insert at the beginning (Requires double pointer to update the head)
void insertAtBeginning(struct Node** headRef, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *headRef;
    *headRef = newNode;
}

// 4. Delete a node by value
void deleteNode(struct Node** headRef, int target) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;

    // Case 1: Head itself holds the target
    if (temp != NULL && temp->data == target) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    // Case 2: Search for the target
    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }

    // Target not found
    if (temp == NULL) return;

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);
}

// 5. Display the list
void display(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// 6. Free the entire list memory
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL; // Initialize empty list

    // Adding elements
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    printf("Linked List: ");
    display(head);

    printf("Deleting 20...\n");
    deleteNode(&head, 20);

    printf("Updated List: ");
    display(head);

    // Clean up memory before exiting
    freeList(head);

    return 0;
}
