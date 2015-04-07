typedef struct {
  int value;
  int col;
  struct list_node *next;
} list_node;

typedef struct {
  list_node *head;
  list_node *tail;
} List;

List* create_list();
void insert_list(List *l, int col, int value);
void print_list(List *l);
int get_value_list(List *l, int col);
void free_list(List *l);
int queue_unvisited_list(List *l, Queue *q, char* visited, int target);
