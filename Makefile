CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = AI.o Board.o CheckMove.o EndGame.o Log.o main.o Player.o Game.o

chess: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o chess

AI.o: AI.c AI.h Board.h
	$(CC) $(CFLAGS) -c AI.c

Board.o: Board.c Board.h
	$(CC) $(CFLAGS) -c Board.c

CheckMove.o: CheckMove.c CheckMove.h Board.h
	$(CC) $(CFLAGS) -c CheckMove.c

EndGame.o: EndGame.c EndGame.h Board.h
	$(CC) $(CFLAGS) -c EndGame.c

Log.o: Log.c Log.h Board.h
	$(CC) $(CFLAGS) -c Log.c

main.o: main.c Board.h Player.h
	$(CC) $(CFLAGS) -c main.c

Player.o: Player.c Player.h
	$(CC) $(CFLAGS) -c Player.c

Game.o: Game.c Game.h
	$(CC) $(CFLAGS) -c Game.c

clean:
	rm -f chess $(OBJ)
