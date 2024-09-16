#include <stdio.h>

#include "tests.h"

int main(void) {
  int failed = 0;
  Suite *all_cases[] = {create_remove_suite(),
                        eq_suite(),
                        sum_suite(),
                        sub_suite(),
                        mult_number_suite(),
                        transpose_suite(),
                        mult_matrix_suite(),
                        get_minor_matrix_suite(),
                        determinant_suite(),
                        calc_complements_suite(),
                        inverse_matrix_suite(),
                        NULL};

  for (Suite **curr_suite = all_cases; *curr_suite != NULL; curr_suite++) {
    printf("\n");
    SRunner *sr = srunner_create(*curr_suite);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed = srunner_ntests_failed(sr) + failed;
    srunner_free(sr);
  }

  printf("\n");

  return failed;
}
