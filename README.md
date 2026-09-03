# Custom `atoi()` and `atof()` in C

## 1. Project Overview

This project implements custom versions of the C standard-library conversion functions `atoi()` and `atof()` without calling the built-in conversion functions.

The project demonstrates character processing, pointers, functions, validation, sign handling, decimal conversion, modular program design, automated testing, compiler warnings, and sanitizer-based verification.

## 2. Objectives

- Convert numeric strings into integers manually.
- Convert numeric strings into floating-point values manually.
- Understand ASCII character-to-digit conversion.
- Handle leading whitespace and optional `+` / `-` signs.
- Detect invalid integer input and integer overflow.
- Separate reusable logic from the user interface.
- Test normal, boundary, invalid, whitespace, and null-input cases.
- Verify the project automatically with GitHub Actions.

## 3. Project Structure

```text
internshopwee/
├── .github/
│   └── workflows/
│       └── ci.yml             # automated build and test workflow
├── src/
│   ├── conversion.c           # atoi/atof implementation
│   ├── conversion.h           # public function declarations
│   └── main.c                  # demonstration program
├── tests/
│   └── test_conversion.c      # automated test suite
├── Makefile                   # build, test, sanitizer commands
└── README.md
```

## 4. Algorithms

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

### Run automated tests

```bash
make test
```

Expected output:

```text
Tests passed: 24/24
```

### Run sanitizers

AddressSanitizer and UndefinedBehaviorSanitizer can be used to detect memory-safety and undefined-behavior problems during testing:

```bash
make sanitize
```

### Without Make

```bash
gcc -Wall -Wextra -Wpedantic -std=c11 src/main.c src/conversion.c -o converter
./converter
```

## 7. Validation and Test Coverage

The test suite covers:

- Positive, negative, and signed integers.
- Leading whitespace.
- Zero and `-0`.
- `INT_MAX` and `INT_MIN` boundaries.
- Integer overflow and underflow rejection.
- Invalid text and sign-only input.
- Positive and negative decimal values.
- Values such as `.5` and `42.`.
- Null pointers and safe failure behavior.

## 8. Continuous Integration

The repository includes a GitHub Actions workflow that builds the project with warnings enabled, runs the automated test suite, and performs a clean rebuild on pushes and pull requests targeting `main`.

## 9. Design Decisions

The conversion functions return `1` for successful conversion and `0` for invalid input. The converted value is returned through an output pointer. This separates conversion logic from printing and makes the functions reusable from other C programs.

The implementation intentionally accepts a numeric prefix in the same educational spirit as `atoi()`/`atof()` rather than implementing every rule of the C standard library functions.

## 10. Limitations

This educational implementation focuses on ordinary signed decimal integers and decimal floating-point input. It does not implement scientific notation, hexadecimal input, locale-specific formats, or every edge-case behavior of the C standard library functions. Floating-point overflow and special values such as `NaN` and infinity are outside the current scope.

## 11. Future Enhancements

- Add scientific notation such as `1.25e3`.
- Add a menu-driven interface for multiple conversions.
- Add strict full-string validation modes.
- Add performance comparisons with standard conversion functions.
- Extend CI with sanitizer execution.

## 12. Academic Value

The project is suitable for demonstrating C fundamentals including strings, arrays, pointers, functions, loops, conditions, numeric conversion, modular programming, error handling, boundary testing, build automation, version control, and continuous integration.
