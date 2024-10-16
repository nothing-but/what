CC = gcc
all: bin/sorted_array bin/sorted_array_tests

CFLAGS = -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES = src/*.h

COMMON_DEPS = $(INCLUDES) Makefile

build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/sorted_array: build/sorted_array.o build/sorted_array_main.o $(COMMON_DEPS)
	$(CC) -o bin/sorted_array build/sorted_array.o build/sorted_array_main.o

bin/sorted_array_tests: build/sorted_array_tests.o build/sorted_array.o build/unity.o $(COMMON_DEPS)
	$(CC) -o bin/sorted_array_tests  build/sorted_array_tests.o build/sorted_array.o build/unity.o

clean:
	rm -f build/* bin/*
