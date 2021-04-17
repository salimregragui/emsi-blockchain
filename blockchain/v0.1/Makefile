# Crypto functions for Blockchain project

CC = gcc
# CC = clang
CFLAGS = -Wall -Werror -Wextra -pedantic -ggdb3  -ftrapv -Wconversion -Wunreachable-code --std=gnu90
LIBS = -I. -L../../crypto -lhblk_crypto -lllist -lssl -lcrypto -pthread
PROVIDED = provided/_blockchain_print.c provided/_blockchain_destroy.c provided/_endianness.c

TASK0 = blockchain_create
TASK1 = block_create
TASK2 = block_destroy
TASK3 = blockchain_destroy
TASK4 = block_hash
TASK5 = blockchain_serialize
TASK6 = blockchain_deserialize
TASK7 = block_is_valid
# STATIC_LIB = libhblk_crypto.a
# SRC = $(wildcard *.c)
# OBJ = $(SRC:.c=.o)

# all: $(STATIC_LIB)

# $(STATIC_LIB): $(OBJ)
# 	ar ru $@ $^
# 	ranlib $@

$(TASK7): $(TASK7).c $(TASK6).c $(TASK5).c $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK7)-main.c $(PROVIDED)
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK6): $(TASK6).c $(TASK5).c $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK6)-main.c $(PROVIDED)
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK5): $(TASK5).c $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK5)-main.c $(PROVIDED)
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK4): $(TASK4).c $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK4)-main.c provided/_blockchain_print.c provided/_blockchain_destroy.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK3): $(TASK3).c $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK3)-main.c provided/_blockchain_print.c provided/_blockchain_destroy.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK2): $(TASK2).c $(TASK1).c $(TASK0).c test/$(TASK2)-main.c provided/_blockchain_print.c provided/_blockchain_destroy.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK1): $(TASK1).c $(TASK0).c test/block_create-main.c provided/_blockchain_print.c provided/_blockchain_destroy.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

$(TASK0): $(TASK0).c test/blockchain_create-main.c provided/_blockchain_print.c provided/_blockchain_destroy.c
	$(CC) $(CFLAGS) -o $@  $^ $(LIBS)

.PHONY: clean, check

clean:
	rm $(OBJ) $(TASK0) $(TASK1) $(TASK2) $(TASK3) $(TASK4) $(TASK5) $(TASK6) $(TASK7)

check:
	betty *.c *.h
