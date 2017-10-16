#ifndef bTree_included
#define bTree_included

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
  struct Node *left;
  struct Node *right;
  char *name;
}node;

/*Creates a Node for the Tree with the name specified*/
node *createNode(char name[]);

/* ASCII Comparison between the first and second strings.
   Returns 2 if First is equal to Second.
   Returns 1 if First is Smaller.
   Returns 0 if First is Greater. */
int compare (char first[], char second[]);

/*Adds a name to the Tree */
void addName(node **h, char *name);

/*Populates Tree from a Text File */
void populateFromFile(node **h, char *name);

/* Writes Tree Names to a file. */
void writeToFile(node *h, FILE **file);

/* Lists all the names in the file from smallest to largest. */
void listNames(node *h);

/*Gets the smallest node from the right side of the tree to replace removed node*/
node **getSmallestFromLargest(node **head);

/*Gets the largest node from the left side of the tree to replace removed node */
node **getLargestFromSmallest(node **head);

/* Removes a name from a tree. */
void removeName(node **head, char name[]);

#endif
