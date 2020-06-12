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