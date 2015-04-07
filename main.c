#include <stdio.h>
#include <stdlib.h>
#include "sparse.h"

int main() {
  printf("Loading...\n");
  
  Sparse *s = create_sparse();
  load_from_file_sparse(s, "sample.sp");
  
  //  print_sparse(s);

  printf("Searching...\n");
  
  bfs(s, 0, 2);

  printf("Freeing...\n");
  
  free_sparse(s);
  free(s);
  
  printf("done!\n");
}
