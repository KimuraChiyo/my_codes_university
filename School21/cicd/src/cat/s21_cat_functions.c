#include "s21_cat_functions.h"

#include <getopt.h>
#include <stdio.h>

struct cat_options arguments(int argc, char* argv[]) {
  struct cat_options options = {0, 0, 0, 0, 0, 0, 0};
  static struct option long_options[] = {{"number-nonblank", 0, NULL, 'b'},
                                         {"number", 0, NULL, 'n'},
                                         {"squeeze-blank", 0, NULL, 's'},
                                         {NULL, 0, NULL, 0}};

  int c;
  int option_index;
  c = getopt_long(argc, argv, "beEnstTv", long_options, &option_index);
  while (c != -1) {
    switch (c) {
      case 'b': {
        options.b = 1;
        options.n = 0;
        break;
      }
      case 'e': {
        options.e = 1;
        options.v = 1;
        break;
      }
      case 'E': {
        options.e = 1;
        break;
      }
      case 'n': {
        if (options.b == 0) {
          options.n = 1;
        }
        break;
      }
      case 's': {
        options.s = 1;
        break;
      }
      case 't': {
        options.t = 1;
        options.v = 1;
        break;
      }
      case 'T': {
        options.t = 1;
        break;
      }
      case 'v': {
        options.v = 1;
        break;
      }
      case '?': {
        options.uncorrflag = 1;
        break;
      }
    }
    c = getopt_long(argc, argv, "beEnstTv", long_options, &option_index);
  }

  return options;
}

int cat(FILE* file, struct cat_options opts, int* line_count) {
  int previous_char = '\n', current_char;

  int count_emptys = 0;
  while ((current_char = fgetc(file)) != EOF) {
    if (opts.s) {
      if (current_char == '\n' && count_emptys >= 2) {
        continue;
      } else if (current_char == '\n' && count_emptys < 2) {
        count_emptys++;
      } else {
        count_emptys = 0;
      }
    }
    if (previous_char == '\n' && (opts.n || (opts.b && current_char != '\n'))) {
      fprintf(stdout, "%6d\t", (*line_count)++);
    }
    if (opts.e && current_char == '\n') {
      fprintf(stdout, "$");
    }
    if (opts.t && current_char == '\t') {
      fprintf(stdout, "^");
      current_char = 'I';
    }
    if (opts.v) {
      if (current_char != '\t' && current_char != '\n') {
        if (current_char > 127) {
          fprintf(stdout, "M-");
        }
        current_char = current_char % 128;
        if (current_char < 32) {
          fprintf(stdout, "^");
          current_char = current_char + 64;
        } else if (current_char == 127) {
          fprintf(stdout, "^");
          current_char = current_char - 64;
        }
      }
    }
    fprintf(stdout, "%c", current_char);
    previous_char = current_char;
  }
  return 0;
}