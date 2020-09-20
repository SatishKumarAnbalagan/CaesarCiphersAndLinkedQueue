/*
* CS5600 - Computer Systems, Project 0
*
* queue.c
*
* Author - Satish Kumar Anbalagan
* NUID - 001351994
* Email ID - anbalagan.s@northeastern.edu
*/

#include <stdio.h>

//Type definitions

typedef struct process {
  int identifier;
  char *name;
} process_t;

typedef struct queue {
  void *data;
} queue_t;

//Function declarations

void enqueue(queue_t *queue, void *element);

void* dequeue(queue_t *queue);
