#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

List* create_list() {
  List *l = (List *) malloc(sizeof(List));
  l->head = NULL;
  l->tail = NULL;
  return l;
}

void insert_list(List *l, int col, int value) {
  if (l->head == NULL) {
    l->head = (list_node *) malloc(sizeof(list_node));
    l->tail = l->head;
  } else {
    l->tail->next = (struct list_node *) malloc(sizeof(list_node));
    l->tail = (list_node *) l->tail->next;
  }

  l->tail->col = col;
  l->tail->value = value;
  l->tail->next = NULL;
}

void print_list(List *l) {
  list_node *pointer = l->head;
  while (pointer != NULL) {
    printf("(%d, %d) ", pointer->col, pointer->value);
    pointer = (list_node *) pointer->next;
  }
  printf("\n");
}

int get_value_list(List *l, int col) {
  list_node *p = l->head;
  while (p != NULL) {
    if (p->col == col) {
      return p->value;
    }
    p = (list_node *) p->next;
  }
  return 0;
}

void free_list(List *l) {
  list_node *p = l->head, *n;
  
  while (p != NULL) {
    n = (list_node *) p->next;
    free(p);
    p = n;
  }
}

SList* queue_unvisited_children_list(List *l, SList *path, Queue *q, char* visited, int target) {
  list_node *p = l->head;

  while (p != NULL) {
    if (target == p->col) {
      insert_slist(path, p->col);
      print_slist(path);
      return path;
    }
    
    if (visited[p->col] == 'n') {
      insert_queue(q, path, p->col);
      visited[p->col] = 's';
    }

    p = (list_node *) p->next;
  }

  free_slist(path);

  return NULL;
}
