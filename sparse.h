#include "queue.h"

#define MAX_SPARSE_HASH 8082842

typedef struct {
  List* rows[MAX_SPARSE_HASH];
} Sparse;

Sparse* create_sparse();
void insert_sparse(Sparse *s, int row, int col, int value);
int get_sparse(Sparse *s, int row, int col);
void print_sparse(Sparse *s);
void load_from_file_sparse(Sparse *s, char *filename);
void free_sparse(Sparse *s);
List* bfs(Sparse *s, int from, int col);
