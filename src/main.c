#include <stdio.h>
#include "conversion.h"

int main(void)
{
    char input[100];
    int int_value;
    double float_value;

    printf("Custom atoi()/atof() converter\n");
    printf("Enter a number: ");

    if (scanf("%99s", input) != 1)
        return 1;

    if (my_atoi(input, &int_value))
        printf("my_atoi : %d\n", int_value);
    else
        printf("my_atoi : input is not a valid integer\n");

    if (my_atof(input, &float_value))
        printf("my_atof : %.6f\n", float_value);
    else
        printf("my_atof : input is not a valid number\n");

    return 0;
}
