SRC = student.c \
	  studentfunc.c
INCLUDE = student.h
C=OLD
ifeq ($(C),NEW)
CC= gcc $(SRC) -Wall -Werror -ggdb3 -lm -o demo
else
CC= gcc $(SRC) -Wall -Werror -std=c99 -ggdb3 -lm -o demo
endif
.PHONY: build
build : $(SRC) $(INCLUDE)
	$(CC) 

.PHONY: clean
clean :
	rm -f demo a.out