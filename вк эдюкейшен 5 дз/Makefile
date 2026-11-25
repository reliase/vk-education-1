CC = gcc
CFLAGS = -O3 -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused \
	-Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal \
	-Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 \
	-Wwrite-strings -Wno-long-long -std=gnu99 -Wstrict-prototypes \
	-Wmissing-prototypes -Wmissing-declarations -Wold-style-definition \
	-Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs

TARGETS = a01.out a02.out a03.out a04.out a05.out a06.out

all: $(TARGETS)

a%.out: task%.o functions.o
	$(CC) $^ -o $@

%.o: %.c functions.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.out

.PHONY: all clean
