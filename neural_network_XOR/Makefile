CC=gcc
CFLAGS=-W -Wall -Werror -std=c99 -lm
LDFLAGS=
EXEC=main
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

main: $(OBJ)
	@$(CC) -o $@ $^ $(CFLAGS)




%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o
	@rm -rf test.txt main
	@rm -rf a.out cmake-build-debug

mrproper: clean
	@rm -rf $(EXEC)
