/* Code Written by: Gerardo Uranga for Computer Architecture Project 1 */
#include <stdio.h>
#include <stdlib.h>
#include "bTreeNode.h"
#include "bTree.h"
#include <string.h>
#define true 1

void userInterface(char *file) {
  char answer;
  FILE *fname;
  node *head;
  head = NULL;
  char *employee;
  employee = (char *) malloc(26);

  /* Pre-Populate the Tree */
  printf("Would you like to populate the current tree with this file? Type y or n.\n");
  scanf(" %c", &answer);
  if (answer == 'y') {
    populateFromFile(&head, file);
  }
  
  while(true) {
    printf("Would you like a list of the employees? Type y or n.\n");
    scanf(" %c", &answer);
    if (answer == 'y') {
      listNames(head);
    }
    
    printf("Would you like to add a new employee? Type y or n.\n");
    scanf(" %c", &answer);
    if (answer == 'y') {
      printf("What is the name of the employee?\n");
      fgets(employee, 26, stdin);
      if (fgets(employee, 26, stdin) != NULL) {
	if (strlen(employee)-1 > 0) {
	  employee[strlen(employee) - 1] = 0;
	  addName(&head, employee);
	  employee = (char *) malloc(26);
	  fname = fopen(file, "w+");
	  writeToFile(head, &fname);
	  fclose(fname);
	}
      }
    }

    printf("Would you like to remove an employee? Type y or n.\n");
    scanf(" %c", &answer);
    if (answer == 'y') {
      printf("What is the name of the employee?\n");
      fgets(employee, 26, stdin);
      if (fgets(employee, 26, stdin) != NULL) {
	if (strlen(employee)-1 > 0) {
	  employee[strlen(employee) - 1] = 0;
	  removeName(&head, employee);
	  employee = (char *) malloc(26);
	  fname = fopen(file, "w+");
	  writeToFile(head, &fname);
	  fclose(fname);
	}
      }
    }
  }
}

int main() {
  printf("What is the name of the file to read and write employees to?\n");
  char *file;
  file = (char *) malloc(sizeof(char));
  fgets(file, 26, stdin);
  if (strlen(file) > 0) {
    file[strlen(file) - 1] = 0;
  }
  userInterface(file);
  return 0;
}
