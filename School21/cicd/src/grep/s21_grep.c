#include "./s21_grep_functions.h"

int main(int argc, char* argv[]) {
  char* patterns[PATT_SIZE];
  char* src_files[argc];
  int count_src_files = 0;
  int count_patterns = 0;
  struct grep_options options = arguments(argc, argv, patterns, &count_patterns,
                                          src_files, &count_src_files);
  if (argc > 1) {
    if (!options.uncorrflag && !options.uncorrpatternfile && count_src_files &&
        count_patterns) {
      char* full_pattern = concat_patterns(patterns, count_patterns);
      for (int i = 0; i < count_src_files; i++) {
        char* filename = src_files[i];
        FILE* file = fopen(filename, "r");
        if (file != NULL) {
          char line[BUFF_SIZE];
          int check_patterns_res;
          int line_pos = 1;
          regmatch_t matching[BUFF_SIZE];
          int matching_lines = 0;
          while (fgets(line, BUFF_SIZE - 1, file) != NULL) {
            check_patterns_res = 0;
            if (check_pattern(line, full_pattern, options, matching,
                              count_src_files, filename, line_pos) == 1) {
              check_patterns_res = 1;
              matching_lines++;
            }
            output_hnv(filename, line, line_pos, check_patterns_res, options,
                       count_src_files);
            line_pos++;
          }
          output_cl(filename, matching_lines, options, count_src_files,
                    line_pos);
          fclose(file);
        } else {
          if (options.s == 0) {
            fprintf(stderr, "./s21_grep: %s: No such file or directory\n",
                    src_files[i]);
          }
        }
      }
      free(full_pattern);
    }
    for (int i = 0; i < count_patterns; i++) {
      free(patterns[i]);
    }
  }
  return 0;
}