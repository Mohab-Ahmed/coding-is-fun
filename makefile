include sources.mk
CC= gcc $(SOURCE) -Wall -O0 -Werror -std=c99 -ggdb3 -lm -o demo

ifeq ($(ERROR),NO)
CC= gcc $(SOURCE) -Wall -O0 -std=c99 -ggdb3 -lm -o demo
endif

.PHONY: build
build : $(SOURCE) 
	$(CC) 

.PHONY: clean
clean :
	rm -f demo a.out