CC = g++
CFLAGS = -c -Wall
all: logs

logs: main.o player.o time.o
	$(CC) $(CFLAGS) main.o player.o time.o -o Logins

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

player.o: player.cpp
	$(CC) $(CFLAGS) player.cpp

time.o: time.cpp
	$(CC) $(CFLAGS) time.cpp
	
clean:
	rm -rf *o Logins