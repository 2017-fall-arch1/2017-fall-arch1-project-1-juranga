/* Code created by: Gerardo Uranga for Lab 1 Computer Architecture */
#include "bTreeNode.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

node *createNode(char name[]) {
  node *newNode;
  newNode = malloc(sizeof(node));
  if (newNode == NULL)
    return NULL;
  newNode->left = newNode->right = NULL;
  newNode->name = name;
  return newNode;
}

/* ASCII Alphabetical Compare: */
int compare(char first[], char second[]) {
  int n = strlen(first);
  if (n > strlen(second))
    n = strlen(second);
  for(int i = 0; i < n; i++) {
    if (first[i] < second[i])
      return 1;
    if (first[i] > second[i])
      return 0;
  }
  if (strlen(first) == strlen(second))
    return 2;
  return 0;
}

void addName(node **head, char *name) {
  if (*head == NULL) {
    *head = createNode(name);
    return;
  }
  if (compare((*head)->name, name) == 0) {
    addName(&((*head)->left), name);
  }
  else if(compare((*head)->name, name) == 1) {
    addName(&((*head)->right), name);
  }
}

void populateFromFile(node **head, char *fileName) {
  FILE *file;
  file = fopen(fileName, "r");
  char *name;
  name = (char *) malloc(26);
  while(fgets(name, 26, file)) {
    if (strlen(name) - 1 > 0) {
      name[strlen(name)-1] = 0;
      addName(&(*head), name);
      name = (char *) malloc(26);
    }
  }
}

void writeToFile(node *head, FILE **file) {
  if (head != NULL) {
    fprintf(*file, "%s\n", head->name);
  }
  if (head->left != NULL) {
    writeToFile(head->left, &(*file));
  }
  if (head->right != NULL) {
    writeToFile(head->right, &(*file));
  }
}

void listNames(node *head) {
  if (head->left != NULL) {
    listNames(head->left);
  }
  printf("%s\n", head->name);
  if (head->right != NULL) {
    listNames(head->right);
  }
}

node **getSmallestFromLargest(node **head) {
  if (*head == NULL)
    return NULL;
  if ((*head)->left == NULL) {
    if ((*head)->right == NULL)
      return &(*head);
    else
      return getSmallestFromLargest(&((*head)->right));
  }
  return getSmallestFromLargest(&((*head)->left));
}

node **getLargestFromSmallest(node **head) {
  if (*head == NULL)
    return NULL;
  if ((*head)->right == NULL) {
    if ((*head)->left == NULL)
      return &(*head);
    else
      return getLargestFromSmallest(&((*head)->left));
  }
  return getLargestFromSmallest(&((*head)->right));
}

void removeName(node **head, char name[]) {
  if (compare((*head)->name, name) == 2) {
    if ((*head)->right == NULL && (*head)->left != NULL) {
      node **tmp;
      tmp = getSmallestFromLargest(&((*head)->left));
      (*head)->name = (*tmp)->name;
      *tmp = NULL;
    }
    else if ((*head)->left == NULL && (*head)->right != NULL){
      node **tmp;
      tmp = getLargestFromSmallest(&((*head)->right));
      (*head)->name = (*tmp)->name;
      *tmp = NULL;
    }
    else if ((*head)->left != NULL && (*head)->right != NULL) {
      node **tmp;
      tmp = getSmallestFromLargest(&((*head)->left));
      (*head)->name = (*tmp)->name;
      *tmp = NULL;
    }
    else
      *head = NULL;
    return;
  }
  if (compare((*head)->name, name) == 0) 
    removeName(&((*head)->left), name);
  else
    removeName(&((*head)->right), name);
}
