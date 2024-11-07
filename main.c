// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Node type to store data
// typedef struct Node {
//     char word[10];
//     int count;
//     struct Node *next;
// } Node;

// // Function to create a node
// Node *createNode(char *input) {
//     Node *node = (Node *)malloc(sizeof(Node));
//     strcpy(node->word, input);
//     node->count = 1;
//     node->next = NULL;
//     return node;
// }

// // Function to find a node in the linked list or reach the end if the key isn't found
// Node *search(Node *head, char *input, Node **prev) {
//     Node *current = head;
//     *prev = NULL;

//     while (current != NULL && strcmp(current->word, input) != 0) {
//         *prev = current;
//         current = current->next;
//     }
//     return current; // Returns either the found node or NULL if not found
// }

// // Function to add a new node or increment and reorder an existing node
// void add(Node **head, char *input) {
//     Node *prev = NULL;
//     Node *foundNode = search(*head, input, &prev);

//     if (foundNode != NULL) {
//         // Word found, increment count
//         foundNode->count++;

//         // Reorder if necessary
//         if (prev != NULL) {
//             prev->next = foundNode->next; // Unlink found node
//         } else {
//             *head = foundNode->next; // Update head if it was the head node
//         }

//         Node *insertionPoint = NULL;
//         Node *iterator = *head;

//         // Find correct insertion point for the incremented node
//         while (iterator != NULL && iterator->count <= foundNode->count) {
//             insertionPoint = iterator;
//             iterator = iterator->next;
//         }

//         if (insertionPoint == NULL) {
//             foundNode->next = *head;
//             *head = foundNode;
//         } else {
//             foundNode->next = insertionPoint->next;
//             insertionPoint->next = foundNode;
//         }
//     } else {
//         // Create and insert new node if word not found
//         Node *newNode = createNode(input);
//         if (*head == NULL || (*head)->count > 1) {
//             newNode->next = *head;
//             *head = newNode;
//         } else {
//             Node *tail = *head;
//             while (tail->next != NULL && tail->next->count <= 1) {
//                 tail = tail->next;
//             }
//             newNode->next = tail->next;
//             tail->next = newNode;
//         }
//     }
// }

// // Function to print the linked list
// void print(Node *head) {
//     while (head != NULL) {
//         printf("%s -> %d\n", head->word, head->count);
//         head = head->next;
//     }
// }

// int main() {
//     char input[10];
//     Node *head = NULL;

//     printf("Enter words [enter 'x' to stop]:\n");
//     int continueLoop = 1;
//     while (continueLoop) {
        
//         scanf("%s", input);

//         if (strcmp(input, "x") == 0) {
//             continueLoop = 0;
//             continue;
//         }

//         add(&head, input);
//     }

//     printf("\nLinked list contents:\n");
//     print(head);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node type to store data
typedef struct Node {
    char word[10];
    int count;
    struct Node *next;
} Node;

// List type to represent the linked list
typedef struct List {
    Node *first;
} List;

// Function to create a node
Node *createNode(char *input) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->word, input);
    node->count = 1;
    node->next = NULL;
    return node;
}

// Function to find a node in the linked list or reach the end if the key isn't found
Node *search(List *list, char *input, Node **prev) {
    Node *current = list->first;
    *prev = NULL;

    while (current != NULL && strcmp(current->word, input) != 0) {
        *prev = current;
        current = current->next;
    }
    return current; // Returns either the found node or NULL if not found
}

// Function to add a new node or increment and reorder an existing node
void add(List *list, char *input) {
    Node *prev = NULL;
    Node *foundNode = search(list, input, &prev);

    if (foundNode != NULL) {
        // Word found, increment count
        foundNode->count++;

        // Reorder if necessary
        if (prev != NULL) {
            prev->next = foundNode->next; // Unlink found node
        } else {
            list->first = foundNode->next; // Update first if it was the head node
        }

        Node *insertionPoint = NULL;
        Node *iterator = list->first;

        // Find correct insertion point for the incremented node
        while (iterator != NULL && iterator->count <= foundNode->count) {
            insertionPoint = iterator;
            iterator = iterator->next;
        }

        if (insertionPoint == NULL) {
            foundNode->next = list->first;
            list->first = foundNode;
        } else {
            foundNode->next = insertionPoint->next;
            insertionPoint->next = foundNode;
        }
    } else {
        // Create and insert new node if word not found
        Node *newNode = createNode(input);
        if (list->first == NULL || list->first->count > 1) {
            newNode->next = list->first;
            list->first = newNode;
        } else {
            Node *tail = list->first;
            while (tail->next != NULL && tail->next->count <= 1) {
                tail = tail->next;
            }
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }
}

// Function to print the linked list
void print(List *list) {
    Node *current = list->first;
    while (current != NULL) {
        printf("%s -> %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    char input[10];
    List list = { NULL }; // Initialize list with first set to NULL

    printf("Enter words [enter 'x' to stop]:\n");
    int continueLoop = 1;
    while (continueLoop) {
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "x") == 0) {
            continueLoop = 0;
            continue;
        }

        add(&list, input);
    }

    printf("\nLinked list contents:\n");
    print(&list);

    return 0;
}