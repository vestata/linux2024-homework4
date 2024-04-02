CC = gcc

SOURCES = $(wildcard *.c)

EXECUTABLES = $(SOURCES:.c=)

all: $(EXECUTABLES)

log: 2024w3q3.c
	$(CC) -o 2024w3q3 $< -lrt
	./2024w3q3
	gnuplot test.gp

%: %.c
	$(CC) -o $@ $<

clean:
	rm -f $(EXECUTABLES)

.PHONY: all clean
