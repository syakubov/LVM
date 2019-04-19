// Solomon Yakubov, 2019
// GPLv3

SRC_FILES = program.c main.c lvmhelper.c
CC_FLAGS = -Wall -Wextra -g -std=c11
CC = cc

all:
	${CC} ${SRC_FILES} ${CC_FLAGS} -o lvm
