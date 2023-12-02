#ifndef QUEUE_H

#define QUEUE_H 

typedef struct Node {
	char* path;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
} Queue;

void initializeQueue(Queue* queue);

void enqueue(Queue* queue, const char* path);

char* dequeue(Queue* queue);

void freeQueue(Queue* queue);

#endif
