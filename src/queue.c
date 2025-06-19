#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

t_queue* create_queue(int max){
    t_queue* queue = (t_queue*)malloc(sizeof(t_queue));
    queue->max = max;
    queue->front = -1;
    queue->rear = -1;

    queue->people = (char**)malloc(max * sizeof(char*));

    for(int i = 0; i < max; i++){
        queue->people[i] = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
    }

    return queue;
}

int enqueue(char* person, t_queue* queue){
    if(is_full(queue)){
        return 0;
    }

    if(is_empty(queue)){
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % queue->max;
    strcpy(queue->people[queue->rear], person);

    return 1;
}

char* dequeue(t_queue* queue){
   if(is_empty(queue)){
    return NULL;
   } 
   
   char* temp = queue->people[queue->front];

   if(size(queue) == 1){
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->max;
    }

    return temp;
}

int is_full(t_queue* queue){
    return (queue->rear + 1) % queue->max == queue->front;
}

int is_empty(t_queue* queue){
    return queue->front == -1;
}

void clear(t_queue* queue){
    queue->front = -1;
    queue->rear = -1;
}

int size(t_queue* queue){
    if (is_empty(queue)) {
        return 0;
    }

    if (queue->rear >= queue->front) {
        return queue->rear - queue->front + 1;
    } else {
        return queue->max - queue->front + queue->rear + 1;
    }
}