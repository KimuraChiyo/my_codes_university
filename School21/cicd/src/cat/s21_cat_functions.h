#include <stdio.h>
#ifndef CAT_FUNC_H
#define CAT_FUNC_H

struct cat_options {
  int b;
  int e;
  int v;
  int n;
  int s;
  int t;
  int uncorrflag;
};

struct cat_options arguments(int argc, char* argv[]);

int cat(FILE* file, struct cat_options opts, int* line_count);
#endif