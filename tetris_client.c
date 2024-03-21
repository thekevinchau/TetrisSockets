#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <ncurses.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#define PORT 9001


int main(){

	//Initializing the client socket
    int net_socket = socket(AF_INET, SOCK_STREAM, 0);

	//specify address for the socket
	struct sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(PORT);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	//Sending a connection out to the server
	int connection_status = connect(net_socket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	//If it doesn't connect to the server then it returns -1 which is an error.
	if (connection_status == -1){
		printf("There was an error connecting to remote socket");
	}


    int packet_no = 0;
	initscr();
	noecho();
	int client_input;
    while (1){
        client_input = getch();

		//If there is no error with the input, then we can send the input over to the server and simultaneously print our transmitted packets.
		if (client_input != ERR){
			send(net_socket, &client_input, sizeof(client_input), 0);
			printw("Packet %d transmitted\n", ++packet_no);
		}

		//If the character we input is a q, then we should quit the game on both server and client side.
		if (client_input == 'q'){
			break;
		}
    }
	endwin();
	close(net_socket);
	printf("Number of packets transmitted %d", packet_no);
    return 0;
}
