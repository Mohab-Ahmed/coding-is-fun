include sources.mk
CC= gcc $(SOURCE) -Wall -O0 -Werror -std=c99 -ggdb3 -lm -o demo

ifeq ($(ERROR),NO)
CC= gcc $(SOURCE) -Wall -O0 -std=c99 -ggdb3 -lm -o demo
endif

.PHONY: display_sources
display_sources :
	@echo "tt.c -> make build SRC=1"
	@echo "strcmp.c -> make build SRC=2"
	@echo "atoix.c -> make build SRC= 3"
	@echo "malloc.c -> make build SRC=4"
	@echo "valgrind.c -> make build SRC=5"
	@echo "struct.c -> make build SRC=6"
	@echo "mem.c -> make build SRC=7"
	@echo "atoid.c -> make build SRC=8"
	@echo "fptr.c -> make build SRC=9"
	@echo "bit.c -> make build SRC=10"
	@echo "sequence.c -> make build SRC=11"
	@echo "enum.c -> make build SRC=12"
	@echo "rectangle.c -> make build SRC=13"
	@echo "retirement.c -> make build SRC=14"
	@echo "find_bits.c -> make build SRC=15"
	@echo "reverse.c -> make build SRC=16"
	@echo "encrypt.c -> make build SRC=17"
	@echo "decrypt.c -> make build SRC=18"
	@echo "rotate_matrix.c -> make build SRC=19"
	@echo "square.c -> make build SRC=20"
	@echo "file.c -> make build SRC=21"
	@echo "getline.c -> make build SRC=22"
	@echo "minesweeper.c -> make build SRC=23"

.PHONY: build
build : $(SOURCE) 
	$(CC) 

.PHONY: clean
clean :
	rm -f demo a.out