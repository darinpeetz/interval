#include <iostream>
#include <limits>
#include <cmath>

#include "minunit.h"
#include "../src/interval.h"

int tests_run = 0;

static char* test_interval_swap_bounds() {
    mu_assert("error, bounds not swapped", Interval(-3, -4)==Interval(-4,-3));
    return 0;
}

static char* test_interval_log_real() {
    mu_assert("error, log should be distributive", log(Interval(1, 2))==Interval(log(1),log(2)));
    return 0;
}

static char* test_interval_log_zero() {
    mu_assert("error, log should return neg inf for zero", log(Interval(0, 2)).a==-std::numeric_limits<double>::infinity());
    return 0;
}

static char * test_interval_exp() {
    mu_assert("error, exp should be distributive", exp(Interval(3,4)) == Interval(exp(3),exp(4)));
    return 0;
}

static char * all_tests() {
    mu_run_test(test_interval_swap_bounds);
    mu_run_test(test_interval_log_real);
    mu_run_test(test_interval_log_zero);
    mu_run_test(test_interval_exp);
    return 0;
}
 
int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);
    
    return result != 0;
}



