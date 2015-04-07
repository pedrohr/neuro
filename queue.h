#include "slist.h"

typedef struct {
  int value;
  int col;
  struct list_node *next;
} list_node;

typedef struct {
  list_node *head;
  list_node *tail;
} List;


typedef struct {
  SList *path;
  struct queue_node *next;
} queue_node;

typedef struct {
  queue_node *last;
  queue_node *first;
  int size;
} Queue;

Queue* create_queue();
void insert_queue(Queue *q, SList *path, int num);
SList* lpop_path_queue(Queue *q);
char empty_queue(Queue *q);

List* create_list();
void insert_list(List *l, int col, int value);
void print_list(List *l);
int get_value_list(List *l, int col);
void free_list(List *l);
SList* queue_unvisited_children_list(List *l, SList *path, Queue *q, char* visited, int target);
