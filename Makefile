CC = g++
CFLAGS = -c -Wall
all: logs

logs: 
	$(CC) $(CFLAGS) main.cpp player.cpp time.cpp -o Logins

main: main.cpp
	$(CC) $(CFLAGS) main.cpp

player: player.cpp
	$(CC) $(CFLAGS) player.cpp	

time: time.cpp
	$(CC) $(CFLAGS) time.cpp
	
clean:
	rm -rf *o Logins