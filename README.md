# Custom `atoi()` and `atof()` in C

## 1. Project Overview

This project implements custom versions of the C standard-library conversion functions `atoi()` and `atof()` without calling the built-in conversion functions.

The project demonstrates character processing, pointers, functions, validation, sign handling, decimal conversion, modular program design, and automated testing.

## 2. Objectives

- Convert numeric strings into integers manually.
- Convert numeric strings into floating-point values manually.
- Understand ASCII character-to-digit conversion.
- Handle leading whitespace and optional `+` / `-` signs.
- Detect invalid integer input and integer overflow.
- Separate reusable logic from the user interface.
- Test the implementation with repeatable test cases.

## 3. Project Structure

```text
internshopwee/
├── src/
│   ├── conversion.c   # atoi/atof implementation
│   ├── conversion.h   # public function declarations
│   └── main.c          # demonstration program
├── tests/
│   └── test_conversion.c
├── Makefile
└── README.md
```

## 4. Algorithm

### Integer conversion

1. Skip leading whitespace.
2. Read an optional sign.
3. Convert each digit using `digit = character - '0'`.
4. Build the result using `value = value * 10 + digit`.
5. Apply the sign.
6. Reject values outside the range of `int`.

### Floating-point conversion

1. Skip leading whitespace and read an optional sign.
2. Build the integer part with repeated multiplication by 10.
3. If a decimal point is found, process fractional digits.
4. Add each fractional digit using a decreasing divisor (`10`, `100`, `1000`, ...).
5. Apply the sign.

## 5. Example

```text
Custom atoi()/atof() converter
Enter a number: -123.45
my_atoi : input is not a valid integer
my_atof : -123.450000
```

For `12345`, the integer conversion returns `12345`; for `123.45`, the floating-point conversion returns `123.450000`.

## 6. Build and Run

### Using Make

```bash
make
./converter
```

### Run tests

```bash
make test
```

Expected test output:

```text
Tests passed: 8/8
```

### Without Make

```bash
gcc -Wall -Wextra -Wpedantic -std=c11 src/main.c src/conversion.c -o converter
./converter
```

## 7. Limitations

This educational implementation intentionally focuses on ordinary signed decimal integers and decimal floating-point input. It does not implement scientific notation, hexadecimal input, locale-specific formats, or every edge-case behavior of the C standard library functions.

## 8. Future Enhancements

- Add scientific notation such as `1.25e3`.
- Add a menu-driven interface.
- Add more boundary and invalid-input tests.
- Add continuous integration using GitHub Actions.
- Add performance comparisons with standard conversion functions.

## 9. Academic Value

The project is suitable for demonstrating C fundamentals including strings, arrays, pointers, functions, loops, conditions, numeric conversion, modular programming, error handling, and testing.
