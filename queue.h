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
#include <stdlib.h>

//Type definitions

typedef struct _process {
  int PID;
  char *name;
} process_t;

typedef struct _node {
  process_t* p;
  struct _node *next;
} node_t;

typedef struct _queue {
  void *data;
  node_t *front;
  node_t *rear;
} queue_t;

//Function declarations
int isempty(queue_t *queue);

void initialize(queue_t *queue);

void display(node_t *head);

void enqueue(queue_t *queue, void *element);

void* dequeue(queue_t *queue);
