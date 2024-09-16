#include <stdio.h>

#include "tests.h"

int main(void) {
  int failed = 0;
  Suite *all_cases[] = {main_utilities_suite(),
                        normalize_utilities_suite(),
                        normalize_suite(),
                        comparisons_suite(),
                        sub_utilities_suite(),
                        sub_suite(),
                        add_suite(),
                        mul_suite(),
                        div_utilities_suite(),
                        div_suite(),
                        converters_utilities_suite(),
                        converters_suite(),
                        others_suite(),
                        NULL};

  for (Suite **curr_suite = all_cases; *curr_suite != NULL; curr_suite++) {
    printf("\n");
    SRunner *sr = srunner_create(*curr_suite);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed = srunner_ntests_failed(sr) || failed;
    srunner_free(sr);
  }

  printf("\n");

  return failed;
}
