/*
* CS5600 - Computer Systems, Project 0
*
* queue.c
*
* Author - Satish Kumar Anbalagan
* NUID - 001351994
* Email ID - anbalagan.s@northeastern.edu
*/

#include "queue.h"

void initialize(queue_t *queue) {
  queue->data = NULL;
  queue->front = NULL;
  queue->rear = NULL;
}

int isempty(queue_t *queue) {
  return (queue->rear == NULL);
}

void display(node_t *head) {
  if(head == NULL) {
    printf("NULL\n");
  }
  else {
    printf("PID = %d, Name = %s\n", head->p->PID, head->p->name);
    display(head->next);
  }
}

void enqueue(queue_t *queue, void *element) {
  node_t *tmp;
  tmp = malloc(sizeof(node_t));
  tmp->p = element;
  tmp->next = NULL;
  if(!isempty(queue)) {
      queue->rear->next = tmp;
      queue->rear = tmp;
  }
  else {
      queue->front = queue->rear = tmp;
  }
}

void* dequeue(queue_t *queue) {
  node_t *tmp;
  process_t* n = queue->front->p;
  tmp = queue->front;
  queue->front = queue->front->next;
  free(tmp);
  return n;
}

int main() {
  queue_t *queue;
  queue = malloc(sizeof(queue_t)); 
  initialize(queue);

  printf("\n");
  printf("##########################\n");
  printf("#  Queue before Enqueue  #\n");
  printf("##########################\n");
  display(queue->front);

  process_t process[3];
  for(int i=0;i<3;i++) {
    process_t *p = &process[i];
    p->PID = i;
    p->name = malloc(sizeof(*p->name)*9);
    sprintf(p->name, "Process%d", i);
    enqueue(queue, p);
    printf("\nQueue after enqueue %d - \n", i);
    display(queue->front);
  }

  printf("\n");
  printf("##########################\n");
  printf("#  Queue before Dequeue  #\n");
  printf("##########################\n");  
  display(queue->front);

  for(int i=0;i<3;i++) {
    dequeue(queue);
    printf("\nQueue after dequeue %d - \n", i);
    display(queue->front);
  }
  
  free(queue);
  return 0;

}