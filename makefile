CC = gcc
CFLAGS = -Wall -Wextra  -std=c99 -pedantic -O3 \
	$(shell pkg-config --cflags sdl2)
LDFLAGS =`sdl-config --libs --cflags`
LDLIBS = $(shell pkg-config --libs sdl2) -lSDL2_image
VALGRIND = valgrind

SRC = $(shell find src -name '*.c')
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}


all: ocr
	mkdir -p output
	


ocr: ${OBJ}
	@echo "Linking ocr binary..."
	@$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

%.o: %.c
	@echo "Building $@..."
	@$(CC) -MMD -o $@ -c $< $(CFLAGS)

-include ${DEP}

.PHONY: clean check-valgrind

clean:
	${RM} ${OBJ}
	${RM} ${DEP}
	${RM} ocr

check-valgrind: ocr
	${VALGRIND} \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--suppressions=.glib.suppression \
		./ocr --test xor
