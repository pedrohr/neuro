#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

SList* create_slist() {
  SList *l = (SList *) malloc(sizeof(SList));
  l->head = NULL;
  l->tail = NULL;
  return l;
}

void insert_slist(SList *l, int value) {
  if (l->head == NULL) {
    l->head = (slist_node *) malloc(sizeof(slist_node));
    l->tail = l->head;
  } else {
    l->tail->next = (struct slist_node *) malloc(sizeof(slist_node));
    l->tail = (slist_node *) l->tail->next;
  }

  l->tail->value = value;
  l->tail->next = NULL;
}

void print_slist(SList *l) {
  slist_node *pointer = l->head;
  while (pointer != NULL) {
    printf("(%d) ", pointer->value);
    pointer = (slist_node *) pointer->next;
  }
  printf("\n");
}

void free_slist(SList *l) {
  slist_node *p = l->head, *n;
  
  while (p != NULL) {
    n = (slist_node *) p->next;
    free(p);
    p = n;
  }
}

int get_last_value_slist(SList *l) {
  return l->tail->value;
}

SList* clone_slist(SList *origin) {
  SList *l = create_slist();

  slist_node *p = origin->head;
  while (p != NULL) {
    insert_slist(l, p->value);
    p = (slist_node *) p->next;
  }
  
  return l; 
}
