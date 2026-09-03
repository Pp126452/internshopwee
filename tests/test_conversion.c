#include <limits.h>
#include <math.h>
#include <stdio.h>

#include "../src/conversion.h"

static int check_int(const char *input, int expected)
{
    int actual;
    return my_atoi(input, &actual) && actual == expected;
}

static int check_int_invalid(const char *input)
{
    int actual;
    return !my_atoi(input, &actual);
}

static int check_double(const char *input, double expected)
{
    double actual;
    return my_atof(input, &actual) && fabs(actual - expected) < 1e-9;
}

static int check_double_invalid(const char *input)
{
    double actual;
    return !my_atof(input, &actual);
}

static int check_double_special(const char *input, double expected)
{
    double actual;
    return my_atof(input, &actual) && fabs(actual - expected) < 1e-12;
}

int main(void)
{
    int passed = 0;
    int total = 20;

    passed += check_int("12345", 12345);
    passed += check_int("-12345", -12345);
    passed += check_int("+42", 42);
    passed += check_int("  99", 99);
    passed += check_int("0", 0);
    passed += check_int("-0", 0);
    passed += check_int("2147483647", INT_MAX);
    passed += check_int("-2147483648", INT_MIN);
    passed += check_int_invalid("2147483648");
    passed += check_int_invalid("-2147483649");
    passed += check_int_invalid("abc");
    passed += check_int_invalid("+");
    passed += check_int_invalid("-");
    passed += check_double("123.45", 123.45);
    passed += check_double("-12.5", -12.5);
    passed += check_double("+0.25", 0.25);
    passed += check_double("42", 42.0);
    passed += check_double_special(".5", 0.5);
    passed += check_double_special("42.", 42.0);
    passed += check_double_invalid(".");

    printf("Tests passed: %d/%d\n", passed, total);
    return passed == total ? 0 : 1;
}
