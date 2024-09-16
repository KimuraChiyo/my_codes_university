#include <getopt.h>
#include <stdio.h>

#include "./s21_cat_functions.h"

int main(int argc, char* argv[]) {
  struct cat_options options = arguments(argc, argv);

  FILE* file = NULL;
  int line_count = 1;
  while (optind < argc) {
    file = fopen(argv[optind], "r");
    if (file != NULL && !options.uncorrflag) {
      cat(file, options, &line_count);
      fclose(file);
    } else {
      fprintf(stderr, "cat: %s: No such file or directory\n", argv[optind]);
    }
    optind++;
  }

  return 0;
}