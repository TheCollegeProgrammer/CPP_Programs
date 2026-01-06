#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void traverse();
void search();
void count_nodes();

int main() {
    int choice;

    while (1) {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Traverse\n");
        printf("8. Search Element\n");
        printf("9. Count Nodes\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_pos(); break;
            case 7: traverse(); break;
            case 8: search(); break;
            case 9: count_nodes(); break;
            case 0: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void insert_begin() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
}

void insert_end() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insert_pos() {
    int pos, i = 1;
    struct Node *newNode, *temp = head;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        insert_begin();
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_begin() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void delete_end() {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void delete_pos() {
    int pos, i = 1;
    struct Node *temp = head, *prev = NULL;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_begin();
        return;
    }

    while (i < pos && temp != NULL) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void traverse() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search() {
    int key, pos = 1;
    struct Node *temp = head;
    printf("Enter element to search: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found!\n");
}

void count_nodes() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total nodes = %d\n", count);
}
