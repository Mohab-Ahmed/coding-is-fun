#this sources.mk file is for all the .c programs in this directory
#	tt.c -> 1
#	strcmp.c -> 2
#	atoix.c -> 3
#	malloc.c -> 4 
#	valgrind.c -> 5
#	struct.c -> 6
#	mem.c -> 7
#	atoid.c -> 8
#	fptr.c -> 9
#	bit.c -> 10
#	sequence.c -> 11
#	enum.c -> 12
#	rectangle.c -> 13
#	retirement.c -> 14 
#	find_bits.c -> 15
#	reverse.c -> 16
#	encrypt.c -> 17
#	decrypt.c -> 18
#	rotate_matrix.c -> 19
#	square.c -> 20
#	file.c -> 21
#	getline.c -> 22
#	minesweeper.c -> 23

ifeq ($(SRC),1)
SOURCE=tt.c
endif

ifeq ($(SRC),2)
SOURCE=strcmp.c
endif

ifeq ($(SRC),3)
SOURCE=atoix.c
endif

ifeq ($(SRC),4)
SOURCE=malloc.c
endif

ifeq ($(SRC),5)
SOURCE=valgrind.c
endif

ifeq ($(SRC),6)
SOURCE=struct.c
endif

ifeq ($(SRC),7)
SOURCE=mem.c
endif

ifeq ($(SRC),8)
SOURCE=atoid.c
endif

ifeq ($(SRC),9)
SOURCE=fptr.c
endif

ifeq ($(SRC),10)
SOURCE=bit.c
endif

ifeq ($(SRC),11)
SOURCE=sequence.c
endif

ifeq ($(SRC),12)
SOURCE=enum.c
endif

ifeq ($(SRC),13)
SOURCE=rectangle.c
endif

ifeq ($(SRC),14)
SOURCE=retirement.c
endif

ifeq ($(SRC),15)
SOURCE=find_bits.c
endif

ifeq ($(SRC),16)
SOURCE=reverse.c
endif

ifeq ($(SRC),17)
SOURCE=encrypt.c
endif

ifeq ($(SRC),18)
SOURCE=decrypt.c
endif

ifeq ($(SRC),20)
SOURCE=square.c
endif

ifeq ($(SRC),21)
SOURCE=file.c
endif

ifeq ($(SRC),22)
SOURCE=getline.c
endif

ifeq ($(SRC),23)
SOURCE=minesweeper.c
endif