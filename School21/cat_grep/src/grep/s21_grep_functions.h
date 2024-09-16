#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 99999
#define PATT_SIZE 512
#ifndef CAT_FUNC_H
#define CAT_FUNC_H

struct grep_options {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  int uncorrflag;
  int uncorrpatternfile;
};

struct grep_options arguments(int argc, char* argv[], char** patterns,
                              int* count_patterns, char** src_files,
                              int* count_src_files);
void patterns_from_file(char* filename, char** patterns, int* count_patterns,
                        int* option);
char* concat_patterns(char** array, int count_patterns);

int check_pattern(char* line, char* pattern, struct grep_options options,
                  regmatch_t* matching, int count_src_files, char* filename,
                  int line_pos);

void output_hnv(char* filename, char* line, int line_pos,
                int check_patterns_res, struct grep_options options,
                int count_src_files);
void output_cl(char* filename, int matching_lines, struct grep_options options,
               int count_src_files, int line_pos);
void output_o(char* filename, char* line, int line_pos, int* exec_res,
              int* check, regex_t reg_exp, regmatch_t* matching,
              struct grep_options options, int count_src_files);

#endif