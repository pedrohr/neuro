#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sparse.h"

inline int _hash_int(int key) {
  return key % MAX_SPARSE_HASH;
}

Sparse* create_sparse() {
  Sparse *s = (Sparse *) malloc(sizeof(Sparse));
  
  int i;
  for (i = 0; i < MAX_SPARSE_HASH; i++) {
    s->rows[i] = NULL;
  }
  
  return s;
}

void insert_sparse(Sparse *s, int row, int col, int value) {
  int hashed = _hash_int(row);
  if (s->rows[hashed] == NULL)
    s->rows[hashed] = create_list();
  insert_list(s->rows[_hash_int(row)], col, value);
}

void print_sparse(Sparse *s) {
  int i;
  printf("{");
  for (i = 0; i < MAX_SPARSE_HASH; i++) {
    if (s->rows[i] != NULL) {
      printf("%d: ", i);
      print_list(s->rows[i]);
    }
  }
  printf("}\n");
}

inline int get_sparse(Sparse *s, int row, int col) {
  int hashed = _hash_int(row);
  if (s->rows[hashed] == NULL) {
    return 0;
  }
  return get_value_list(s->rows[hashed], col);
}

void _interpret_line(char *line, int read, int *row, int *col, int *value) {
  char buffer[30], item = '1';
  short int i, b = 0;
  
  memset(buffer, '\0', 30);
  
  for (i = 0; i < read; i++) {
    if (line[i] == ' ') {
      buffer[b] = '\0';
      if (item == '1') {
	*row = atoi(buffer);
	item = '2';
      } else {
	*col = atoi(buffer);
      }
      memset(buffer, '\0', 30);
      b = 0;
    } else {
      buffer[b] = line[i];
      b++;
    }
  }
  buffer[b] = '\0';
  *value = atoi(buffer);
}

void load_from_file_sparse(Sparse *s, char *filename) {
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Failure opening file\n");
    return;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  int row, col, value;

  while ((read = getline(&line, &len, f)) != -1) {
    _interpret_line(line, read, &row, &col, &value);
    insert_sparse(s, row, col, value);
  }

  free(line);  
  fclose(f);
}

inline void free_sparse(Sparse *s) {
  int i;
  for (i = 0; i < MAX_SPARSE_HASH; i++) {
    if (s->rows[i] != NULL) {
      free_list(s->rows[i]);
    }
    free(s->rows[i]);
  }
}

List* bfs(Sparse *s, int from, int to) {
  if (s->rows[_hash_int(from)] == NULL) {
    return NULL;
  }

  Queue *q;
  int instance;
  char visited[MAX_SPARSE_HASH];
  SList *path;
  
  memset(visited, 'n', MAX_SPARSE_HASH);
  
  q = create_queue();
  
  insert_queue(q, NULL, from);

  while (empty_queue(q) == 'n') {
    path = lpop_path_queue(q);
    instance = get_last_value_slist(path);

    visited[instance] = 'y';

    if (s->rows[instance] == NULL) {
      if (instance == to) {
	printf("Path found!\n");
	return NULL; // TODO: return path
      }
    } else if (queue_unvisited_children_list(s->rows[instance], path, q, visited, to) != NULL) {
      printf("Path found!\n");
      return NULL; // TODO: return path
    }
  }

  printf("No path found!\n");
  return NULL;
}
