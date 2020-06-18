SRC= cards.c main.c deck.c eval.c input.c future.c
HEADER=cards.h deck.h eval.h input.h future.h

CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99

ifeq ($(ERROR),NO)
CFLAGS=-ggdb3 -Wall -pedantic -std=gnu99
endif

OBJ = $(SRC:.c=.o)

%.o : %.c $(HEADER)
	gcc $< -c $(CFLAGS) -o $@ 
	
demo: $(OBJ)
	gcc -o demo $(CFLAGS) $(OBJ)
clean:
	rm demo $(OBJ)