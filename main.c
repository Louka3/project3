#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a Node type to store data
typedef struct Node {
    char word[10]; 
    int count;
    struct Node *next;
} Node;

// function to create a node
Node *createNode(char *input) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->word, input);
    node->count = 1;
    node->next = NULL;
    return node;
}
// function to insert a new node or increase the count of a current node
void search(Node **head, char *input) {
    Node *current = *head, *prev = NULL;
    while (current != NULL && strcmp(current->word, input) != 0) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        // Word found, increment count
        current->count++;

        // Reorder if necessary
        if (prev != NULL) {
            prev->next = current->next; // Unlink current node
        } else {
            *head = current->next; // Unlink if it was the head node
        }

        Node *insertionPoint = NULL;
        Node *iterator = *head;

        // Find the correct insertion point for the incremented node
        while (iterator != NULL && iterator->count <= current->count) {
            insertionPoint = iterator;
            iterator = iterator->next;
        }

        if (insertionPoint == NULL) {
            current->next = *head;
            *head = current;
        } else {
            current->next = insertionPoint->next;
            insertionPoint->next = current;
        }
    } else {
        Node *newNode = createNode(input);
        // find where to place the new node
        if (*head == NULL || (*head)->count > 1) {
            newNode->next = *head;
            *head = newNode;
        } else {
            Node *tail = *head;
            while (tail->next != NULL && tail->next->count <= 1) {
                tail = tail->next;
            }
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%s -> %d\n", head->word, head->count);
        head = head->next;
    }
}

int main() {
    char input[10];
    Node *head = NULL;

    printf("Enter words [enter 'x' to stop]:\n");
    int continueLoop = 1;
    while (continueLoop) {
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "x") == 0) {
            continueLoop = 0; // Exit loop if user inputs 'x'
            continue;
        }

        search(&head, input);
    }

    printf("\nLinked list contents:\n");
    printList(head);

    // Free the linked list memory
    // Node *temp;
    // while (head != NULL) {
    //     temp = head;
    //     head = head->next;
    //     free(temp);
    // }

    return 0;
}


