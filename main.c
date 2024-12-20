#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node type to store data in my list
typedef struct Node {
    char word[10];
    int count;
    struct Node *next;
} Node;

// Type for the linked list
typedef struct LinkedList {
    Node *head;
} LinkedList;

// Create a node
Node *createNode(char *input) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->word, input);
    node->count = 1;
    node->next = NULL;
    return node;
}

// Find a node in the linked list or reach the end if the input is not found
Node *search(LinkedList *list, char *input, Node **prev) {
    Node *current = list->head;
    *prev = NULL;

    while (current != NULL && strcmp(current->word, input) != 0) {
        *prev = current;
        current = current->next;
    }
    return current; // Returns either the found node or NULL
}

// Add a new node or increment and reorder list
void add(LinkedList *list, char *input) {
    Node *prev = NULL;
    Node *foundNode = search(list, input, &prev);

    if (foundNode != NULL) {
        foundNode->count++;
        // Reorder if necessary
        if (prev != NULL) {
            prev->next = foundNode->next; // Link the nodes around the foundNode in order to move foundNode
        } else {
            list->head = foundNode->next; // Update head if it was the head node
        }
        Node *insertionPoint = NULL;
        Node *iterator = list->head;
        // Find correct insertion point for the incremented node
        while (iterator != NULL && iterator->count <= foundNode->count) {
            insertionPoint = iterator;
            iterator = iterator->next;
        }

        if (insertionPoint == NULL) {
            foundNode->next = list->head;
            list->head = foundNode;
        } else {
            foundNode->next = insertionPoint->next;
            insertionPoint->next = foundNode;
        }
    } else {
        // Create new node if word isn't found in the list
        Node *newNode = createNode(input);
        if (list->head == NULL || list->head->count > 1) {
            newNode->next = list->head;
            list->head = newNode;
        } else {
            Node *temp = list->head;
            while (temp->next != NULL && temp->next->count <= 1) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Iterates through and prints the whole linked list
void print(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%s -> %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    char input[10];
    LinkedList list = { NULL }; // Create the linked list
    printf("Enter words [enter 'x' to stop]:\n");
    int continueLoop = 1;
    while (continueLoop) {
        printf("--> ");
        scanf("%s", input);
        if (strcmp(input, "x") == 0) {
            continueLoop = 0;
            continue;
        }
        add(&list, input);
    }

    printf("\n---List---\n");
    print(&list);

    // free the memory
    Node *toFree;
    Node *current = list.head;
    while (current != NULL) {
        toFree = current;
        current = current->next;
        free(toFree);
    }

    return 0;
}
/**
 Output:
 Enter words [enter 'x' to stop]:
--> ab
--> ab
--> bc
--> cd
--> ef
--> gh
--> ab
--> x

---List---
bc -> 1
cd -> 1
ef -> 1
gh -> 1
ab -> 3
 */