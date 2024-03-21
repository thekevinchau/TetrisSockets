PROJECT TITLE: CISC450 TCP Socket Programming Project 1

PROJECT DESCRIPTION:
- Using a forked tetris game, we were tasked with using socket programming in C to control the server's Tetris game from a client connecting to the server. 
- We used the socket.h, netinet, and ncurses library to accomplish this task.

RELEVANT FILES:
- tetris_client.c : This is our client that contains code to connect to the server and to handle keyboard input exactly the same as the server.
- tetris.c : This is the server that listens for a connection to its port. It contains code that opens a socket and waits for a connection, and processes client-side key inputs to control its game. It renders the game and scores.

HOW TO RUN THE PROJECT:
- Currently, the port number is hard-coded into the clientside and serverside's preprocessor directive named "PORT" at the very top. If there is any need to change the port number, here is where you would change it:
    - tetris.c line 16
    - tetris_client.c line 10
- Included is a makefile embedded with two commands to run the program.
    - Firstly, type "make all" without quotes to compile the tetris server and the client. Note that make all also executes the server and opens up the server to listen for a connection.
    - After typing "make all", the server is now listening for a connection. Open another terminal in the same directory and type "./client" into the terminal to execute the client executable.
    - At this point, the tetris board should appear and you may now use "WASD" in the client's terminal to play tetris.
    - If at any point you would like to exit the game, you may press the letter "q" on your keyboard and it should end the game on both client and server side.

CREDITS:
    - Najib Ghadri (Tetris200Lines)