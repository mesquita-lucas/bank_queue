#ifndef QUEUE_H
#define QUEUE_H

#define MAX_NAME_LENGTH 12

typedef struct queue{
    char** people;
    int max;
    int rear;
    int front;
} t_queue;

t_queue* create_queue(int max);

int enqueue(char* person, t_queue* queue);

char* dequeue(t_queue* queue);

int is_empty(t_queue* queue);

int is_full(t_queue* queue);

void clear(t_queue* queue);

int size(t_queue* queue);

#endif