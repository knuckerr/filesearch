#include "queue.h"
#include <stdlib.h>
#include <string.h>

void initializeQueue(Queue *queue) { queue->front = queue->rear = NULL; }

void enqueue(Queue *queue, const char *path) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->path =
      (char *)malloc(strlen(path) + 1); // +1 for the null terminator
  strcpy(newNode->path, path);
  newNode->next = NULL;

  if (queue->rear == NULL) {
    queue->front = queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

char *dequeue(Queue *queue) {
  if (queue->front == NULL) {
    return NULL;
  }

  Node *temp = queue->front;
  char *path = temp->path;

  queue->front = queue->front->next;

  if (queue->front == NULL) {
    queue->rear = NULL;
  }

  free(temp);

  return path;
}

void freeQueue(Queue *queue) {
  while (queue->front != NULL) {
    Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp->path);
    free(temp);
  }
  queue->rear = NULL;
}
