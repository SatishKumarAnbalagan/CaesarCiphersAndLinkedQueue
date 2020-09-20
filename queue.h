/*
* CS5600 - Computer Systems, Project 0
*
* queue.h
*
* Author - Satish Kumar Anbalagan
* NUID - 001351994
* Email ID - anbalagan.s@northeastern.edu
*/

#include <stdio.h>

//Type definitions

typedef struct _process {
  int identifier;
  char *name;
} process_t;

typedef struct _queue {
  void *data;
} queue_t;

//Function declarations

void enqueue(queue_t *queue, void *element);

void* dequeue(queue_t *queue);
