#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char word[10];
  int count;
  struct Node *next;
} Node;

Node *createNode(char *word) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  strcpy(newNode->word, word);
  newNode->count = 1;
  newNode->next = NULL;
  return newNode;
}

