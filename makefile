CC = C++
CFLAGS = -Wall

all:
		$(CC) prog.c -o prog
clean:
		rm -f prog
