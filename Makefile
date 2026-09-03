CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
SANITIZE_FLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g

all: converter

converter: src/main.c src/conversion.c src/conversion.h
	$(CC) $(CFLAGS) src/main.c src/conversion.c -o converter

test: tests/test_conversion.c src/conversion.c src/conversion.h
	$(CC) $(CFLAGS) tests/test_conversion.c src/conversion.c -lm -o test_converter
	./test_converter

sanitize: tests/test_conversion.c src/conversion.c src/conversion.h
	$(CC) $(CFLAGS) $(SANITIZE_FLAGS) tests/test_conversion.c src/conversion.c -lm -o test_converter_sanitize
	./test_converter_sanitize

clean:
	rm -f converter test_converter test_converter_sanitize
