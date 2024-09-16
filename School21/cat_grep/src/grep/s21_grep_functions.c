#include "./s21_grep_functions.h"

struct grep_options arguments(int argc, char* argv[], char** patterns,
                              int* count_patterns, char** src_files,
                              int* count_src_files) {
  struct grep_options options = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  static struct option long_options[] = {{"regexp", 1, NULL, 'e'},
                                         {"ignore-case", 0, NULL, 'i'},
                                         {"invert-match", 0, NULL, 'v'},
                                         {"count", 0, NULL, 'c'},
                                         {"files-with-matches", 0, NULL, 'l'},
                                         {"line-number", 0, NULL, 'n'},
                                         {"no-filename", 0, NULL, 'h'},
                                         {"no-messages", 0, NULL, 's'},
                                         {"file", 1, NULL, 'f'},
                                         {"only-matching", 0, NULL, 'o'},
                                         {NULL, 0, NULL, 0}};

  int c, option_index;
  c = getopt_long(argc, argv, "e:ivclnhsf:o", long_options, &option_index);
  while (c != -1) {
    switch (c) {
      case 'e': {
        options.e = 1;
        patterns[*(count_patterns)] =
            malloc(sizeof(char) * (strlen(optarg) + 1));
        strcpy(patterns[(*count_patterns)++], optarg);
        break;
      }
      case 'i': {
        options.i = 1;
        break;
      }
      case 'v': {
        options.v = 1;
        break;
      }
      case 'c': {
        options.c = 1;
        break;
      }
      case 'l': {
        options.l = 1;
        break;
      }
      case 'n': {
        options.n = 1;
        break;
      }
      case 'h': {
        options.h = 1;
        break;
      }
      case 's': {
        options.s = 1;
        break;
      }
      case 'f': {
        options.f = 1;
        patterns_from_file(optarg, patterns, count_patterns,
                           &options.uncorrpatternfile);
        break;
      }
      case 'o': {
        options.o = 1;
        break;
      }
      case '?': {
        options.uncorrflag = 1;
        break;
      }
    }
    c = getopt_long(argc, argv, "e:ivclnhsf:o", long_options, &option_index);
  }
  if (argc > 1) {
    if (options.e || options.f) {
      for (int i = optind; i < argc; i++) {
        src_files[(*count_src_files)++] = argv[i];
      }
    } else {
      patterns[*(count_patterns)] =
          malloc(sizeof(char) * (strlen(argv[optind]) + 1));
      strcpy(patterns[(*count_patterns)++], argv[optind++]);
      for (int i = optind; i < argc; i++) {
        src_files[(*count_src_files)++] = argv[i];
      }
    }
  }
  return options;
}

void patterns_from_file(char* filename, char** patterns, int* count_patterns,
                        int* option) {
  FILE* file = fopen(filename, "r");
  if (file != NULL) {
    char buffer[BUFF_SIZE];
    int pos = 0;
    char symbol = fgetc(file);
    while (symbol != EOF) {
      buffer[pos++] = symbol;
      symbol = fgetc(file);
    }
    buffer[pos] = '\0';
    char* pattern = strtok(buffer, "\n");
    while (pattern != NULL) {
      patterns[*(count_patterns)] =
          malloc(sizeof(char) * (strlen(pattern) + 1));
      strcpy(patterns[(*count_patterns)++], pattern);
      pattern = strtok(NULL, "\n");
    }
    fclose(file);
  } else {
    fprintf(stderr, "./s21_grep: %s: No such file or directory\n", filename);
    *option = 1;
  }
}

int check_pattern(char* line, char* pattern, struct grep_options options,
                  regmatch_t* matching, int count_src_files, char* filename,
                  int line_pos) {
  regex_t reg_exp;
  int comp_res, exec_res;
  int check = 0;
  comp_res = regcomp(&reg_exp, pattern,
                     options.i ? REG_EXTENDED | REG_ICASE : REG_EXTENDED);
  if (comp_res == 0) {
    exec_res = regexec(&reg_exp, line, BUFF_SIZE - 1, matching, 0);
    if (exec_res == 0) {
      check = 1;
      if (options.o) {
        output_o(filename, line, line_pos, &exec_res, &check, reg_exp, matching,
                 options, count_src_files);
      }
    }
  }
  regfree(&reg_exp);
  return check;
}
void output_hnv(char* filename, char* line, int line_pos,
                int check_patterns_res, struct grep_options options,
                int count_src_files) {
  int need_do_output = !options.o && !options.c && !options.l &&
                       ((check_patterns_res && !options.v) ||
                        (check_patterns_res == 0 && options.v));
  if (count_src_files > 1 && options.h == 0 && need_do_output) {
    fprintf(stdout, "%s:", filename);
  }
  if (options.n && need_do_output) {
    fprintf(stdout, "%d:", line_pos);
  }
  if (need_do_output) {
    fprintf(stdout, "%s", line);
  }
}

void output_cl(char* filename, int matching_lines, struct grep_options options,
               int count_src_files, int line_pos) {
  if (options.c && !options.l) {
    if (count_src_files > 1 && options.h == 0) {
      fprintf(stdout, "%s:", filename);
    }
    if (!options.v) {
      fprintf(stdout, "%d\n", matching_lines);
    } else {
      fprintf(stdout, "%d\n", line_pos - matching_lines - 1);
    }
  }
  if (options.l) {
    fprintf(stdout, "%s\n", filename);
  }
}
void output_o(char* filename, char* line, int line_pos, int* exec_res,
              int* check, regex_t reg_exp, regmatch_t* matching,
              struct grep_options options, int count_src_files) {
  int need_do_o_output = !(options.c || options.l || options.v);
  char* line_ptr = line;
  while ((*exec_res =
              regexec(&reg_exp, line_ptr, BUFF_SIZE - 1, matching, 0)) == 0) {
    *check = 1;
    if (need_do_o_output) {
      if (count_src_files > 1 && options.h == 0) {
        fprintf(stdout, "%s:", filename);
      }
      if (options.n) {
        fprintf(stdout, "%d:", line_pos);
      }
      fprintf(stdout, "%.*s\n", (int)(matching[0].rm_eo - matching[0].rm_so),
              line_ptr + matching[0].rm_so);
    }
    line_ptr += matching[0].rm_eo;
  }
}

char* concat_patterns(char** array, int count_patterns) {
  int lenght = 0;
  char* ptr;

  for (int i = 0; i < count_patterns; i++) {
    lenght += (strlen(array[i]) + 1);
  }

  ptr = malloc(sizeof(char) * (lenght + count_patterns - 1));
  if (ptr != NULL) {
    *ptr = '\0';
    for (int i = 0; i < count_patterns; i++) {
      strcat(ptr, array[i]);
      if (i != count_patterns - 1) {
        strcat(ptr, "|");
      }
    }
  }
  return ptr;
}
