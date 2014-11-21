CC = g++
CFLAGS = -c -Wall
all: logs

logs: 
	$(CC) $(CFLAGS) main.cpp player.cpp time.cpp -o Logins

main: main.cpp
	$(CC) $(CFLAGSS) main.cpp

player: player.cpp
	$(CC) $(CFLAGSS) player.cpp	

time: time.cpp
	$(CC) $(CFLAGSS) time.cpp
	
clean:
	rm -rf *o Logins