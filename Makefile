CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11

all: converter

converter: src/main.c src/conversion.c src/conversion.h
	$(CC) $(CFLAGS) src/main.c src/conversion.c -o converter

test: tests/test_conversion.c src/conversion.c src/conversion.h
	$(CC) $(CFLAGS) tests/test_conversion.c src/conversion.c -lm -o test_converter
	./test_converter

clean:
	rm -f converter test_converter
