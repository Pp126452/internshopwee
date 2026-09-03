#include <stdio.h>
#include <math.h>
#include "../src/conversion.h"

static int check_int(const char *input, int expected)
{
    int actual;
    return my_atoi(input, &actual) && actual == expected;
}

static int check_double(const char *input, double expected)
{
    double actual;
    return my_atof(input, &actual) && fabs(actual - expected) < 1e-9;
}

int main(void)
{
    int passed = 0;
    int total = 8;

    passed += check_int("12345", 12345);
    passed += check_int("-12345", -12345);
    passed += check_int("+42", 42);
    passed += check_int("  99", 99);
    passed += check_double("123.45", 123.45);
    passed += check_double("-12.5", -12.5);
    passed += check_double("+0.25", 0.25);
    passed += check_double("42", 42.0);

    printf("Tests passed: %d/%d\n", passed, total);
    return passed == total ? 0 : 1;
}
