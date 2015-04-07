#include <stdlib.h>
#include "queue.h"

Queue* create_queue() {
  Queue *q = (Queue *) malloc(sizeof(Queue));
  q->first = NULL;
  q->last = NULL;
  return q;
}

void insert_queue(Queue *q, SList *path, int num) {
  if (q->first == NULL) {
    q->first = (queue_node *) malloc(sizeof(queue_node));
    q->last = q->first;
  } else {
    q->last->next = (struct queue_node *) malloc(sizeof(queue_node));
    q->last = (queue_node *) q->last->next;
  }

  if (path == NULL) {
    q->last->path = create_slist();
  } else {
    q->last->path = clone_slist(path);
  }

  insert_slist(q->last->path, num);
  q->last->next = NULL;
}

SList* lpop_path_queue(Queue *q) {
  SList* path = q->first->path;
  
  queue_node *p = q->first;
  q->first = (queue_node *) q->first->next;
  free(p);
  
  return path;
}

char empty_queue(Queue *q) {
  if (q->first == NULL) {
    return 'y';
  }

  return 'n';
}
