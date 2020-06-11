#this sources.mk file is for all the .c programs in this directory
#	tt.c -> 1
#	strcmp.c -> 2

ifeq ($(SRC),1)
SOURCE=tt.c
endif

ifeq ($(SRC),2)
SOURCE=strcmp.c
endif
