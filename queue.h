/**
 * CS5600 - Computer Systems, Project 0
 *
 * queue.h
 * 
 * Linked queue header file
 *
 * Author - Satish Kumar Anbalagan
 * Date - Sept 17, 2020
 * Email ID - anbalagan.s@northeastern.edu
 */

#include <stdio.h>
#include <stdlib.h>

//Type definitions

/**
 * Type definition of a Process with its identifier and name field.
 */
typedef struct _process {
    int PID;    //process identifier
    char *name;    //process name
} process_t;

/**
 * Type definition of linked queue node with process  and next node field.
 */
typedef struct _node {
    process_t* p;    //current process
    struct _node *next;
} node_t;

/**
 * Type definition of generic queue
 */
typedef struct _queue {
    void *data;
} queue_t;

node_t *front;    // node front in queue
node_t *rear;    // node behind in queue

//Function declarations

/**
 * Checks if the queue is empty.
 * @param queue - pointer to the linked queue
 * @return int if queue is empty return's 1, else 0 
 */
int isempty(queue_t *queue);

/**
 * initializes the linked queue to NULL.
 * @param queue - pointer to the linked queue 
 */
void initialize(queue_t *queue);

/**
 * displays the contents of the node in the linked queue.
 * @param head - pointer to the node in the linked queue
 */
void display(node_t *head);

/**
 * function to add elements to the linked queue.
 * @param queue - pointer to the linked queue
 * @param element - pointer to the process in the node
 */
void enqueue(queue_t *queue, void *element);

/**
 * function to remove elements from the linked queue.
 * @param queue - pointer to the linked queue
 * @return void pointer - here, process_t removed
 */
void* dequeue(queue_t *queue);
