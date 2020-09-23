/**
 * CS5600 - Computer Systems, Project 0
 *
 * queue.c
 * 
 * Linked queue source file
 *
 * Author - Satish Kumar Anbalagan
 * Date - Sept 17, 2020
 * Email ID - anbalagan.s@northeastern.edu
 */

#include "queue.h"
#define MAX_NUMBER_OF_PROCESS    7    //maximum processes

void initialize(queue_t *queue)
{
    queue->data = NULL;
    front = NULL;
    rear = NULL;
}

int isempty(queue_t *queue)
{
    return (rear == NULL);
}

void display(node_t *head)
{
    if(head == NULL) {
        printf("NULL\n");
    }
    else {
        printf("%s->", head->p->name);
        display(head->next);
    }
}

void enqueue(queue_t *queue, void *element)
{
    node_t *tmp;
    tmp = (node_t *) malloc(sizeof(*tmp));
    tmp->p = element;
    tmp->next = NULL;
    if(!isempty(queue)) {
        rear->next = tmp;
        rear = tmp;
    }
    else {
        queue->data = front = rear = tmp;
    }
}

void* dequeue(queue_t *queue)
{
    node_t *tmp;
    process_t* n = front->p;
    tmp = front;
    front = front->next;
    queue->data = front;
    free(tmp);
    return n;
}

int main()
{
    queue_t *queue;
    queue = (queue_t *) malloc(sizeof(*queue)); 
    initialize(queue);

    printf("\n");
    printf("##########################\n");
    printf("#  Queue before Enqueue  #\n");
    printf("##########################\n");
    display(queue->data);

    printf("\n");
    printf("##########################\n");
    printf("#         Enqueue        #\n");
    printf("##########################\n");

    process_t process[MAX_NUMBER_OF_PROCESS];
    for(int i=0;i<MAX_NUMBER_OF_PROCESS;i++) {
        process_t *p = &process[i];
        p->PID = i;
        p->name = malloc(sizeof(*p->name)*9);
        sprintf(p->name, "Process%d", i);
        enqueue(queue, p);
        printf("Enqueued %s .....\t", p->name);
        display(queue->data);
    }

    printf("\n");
    printf("##########################\n");
    printf("#  Queue before Dequeue  #\n");
    printf("##########################\n");  
    display(queue->data);

    printf("\n");
    printf("##########################\n");
    printf("#         Dequeue        #\n");
    printf("##########################\n"); 

    for(int i=0;i<MAX_NUMBER_OF_PROCESS;i++) {
        process_t* dequeuedProcess =  dequeue(queue);
        printf("Dequeued %s .....\t", dequeuedProcess->name);
        display(queue->data);
    }

    free(queue);
    return 0;

}
