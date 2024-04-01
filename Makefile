CC = gcc

SOURCES = $(wildcard *.c)

EXECUTABLES = $(SOURCES:.c=)

all: $(EXECUTABLES)

%: %.c
	$(CC) -o $@ $<

clean:
	rm -f $(EXECUTABLES)

.PHONY: all clean
