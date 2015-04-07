typedef struct {
  int value;
  struct slist_node *next;
} slist_node;

typedef struct {
  slist_node *head;
  slist_node *tail;
} SList;

SList* create_slist();
void insert_slist(SList *l, int value);
void print_slist(SList *l);
void free_slist(SList *l);
int get_last_value_slist(SList *l);
SList* clone_slist(SList *origin);
