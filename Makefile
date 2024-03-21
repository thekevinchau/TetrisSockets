all:
	gcc -o server tetris.c -lncurses
	gcc -o client tetris_client.c -lncurses
	./server

run_client:
	./client