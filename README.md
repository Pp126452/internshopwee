# Custom atoi() and atof() in C

## Project Description

This project implements custom versions of the C standard library
functions `atoi()` and `atof()` without directly using the built-in
conversion functions.

## Features

- String to integer conversion
- String to floating-point conversion
- Positive numbers
- Negative numbers
- Explicit `+` sign
- Decimal numbers
- Manual character-to-number conversion
- Function-based implementation

## Functions

### my_atoi()

Converts a numeric string into an integer.

Example:

Input:
12345

Output:
12345

### my_atof()

Converts a numeric string into a floating-point number.

Example:

Input:
123.45

Output:
123.45

## Compilation

```bash
gcc vector.c -o program
