CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
AR = ar -rcs
RM = rm -f
CTAGS = ctags
TAGS = .tags

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

.PHONY: all clean distclean oclean tags libhblk_crypto.a

all: libhblk_crypto.a

clean: oclean
	$(RM) libhblk_crypto.a

distclean: clean
	$(RM) $(TAGS)

oclean:
	$(RM) $(OBJ)

tags:
	$(CTAGS) -f $(TAGS) -R

libhblk_crypto.a: $(OBJ)
	$(AR) $@ $^
