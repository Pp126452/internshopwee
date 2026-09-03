#include "conversion.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>

int my_atoi(const char *str, int *result)
{
    long value = 0;
    int sign = 1;

    if (str == NULL || result == NULL)
        return 0;

    while (isspace((unsigned char)*str))
        str++;

    if (*str == '+' || *str == '-') {
        if (*str == '-')
            sign = -1;
        str++;
    }

    if (!isdigit((unsigned char)*str))
        return 0;

    while (isdigit((unsigned char)*str)) {
        int digit = *str - '0';
        if (value > (LONG_MAX - digit) / 10)
            return 0;
        value = value * 10 + digit;
        str++;
    }

    value *= sign;

    if (value < INT_MIN || value > INT_MAX)
        return 0;

    *result = (int)value;
    return 1;
}

int my_atof(const char *str, double *result)
{
    double value = 0.0;
    double divisor = 10.0;
    int sign = 1;
    int digits = 0;

    if (str == NULL || result == NULL)
        return 0;

    while (isspace((unsigned char)*str))
        str++;

    if (*str == '+' || *str == '-') {
        if (*str == '-')
            sign = -1;
        str++;
    }

    while (isdigit((unsigned char)*str)) {
        value = value * 10.0 + (*str - '0');
        str++;
        digits = 1;
    }

    if (*str == '.') {
        str++;
        while (isdigit((unsigned char)*str)) {
            value += (*str - '0') / divisor;
            divisor *= 10.0;
            str++;
            digits = 1;
        }
    }

    if (!digits)
        return 0;

    *result = sign * value;
    return 1;
}
