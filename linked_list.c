#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end
void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    // If the linked list is empty
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Traverse to the end and insert
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to delete a node by value
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
free(temp);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not found
    if (temp == NULL) {
        printf("Element %d not found.\n", key);
        return;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);
}

// Function to traverse and print the list
void traverse(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    printf("Linked list: ");
traverse(head);

    deleteNode(&head, 20);
    printf("After deletion: ");
    traverse(head);

    deleteNode(&head, 40); // Try to delete non-existing element

    return 0;
}
