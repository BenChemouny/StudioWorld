/****************************************
* Student Name: Nadav and Ben            *
* Exercise Name:  EX-4              *
* File description:  TCPServer.cpp              *
****************************************/
#include "TCPServer.h"
#include "Recv.h"
#include <iostream>
using namespace std;


TCPServer::TCPServer(int port)
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("error creating socket");
	}

	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);

	if(bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
		perror("error binding socket");
	}
	if(listen(sock, 5) < 0)
	{
		perror("error listening to a socket");
	}

	struct sockaddr_in client_sin;
	unsigned int addr_len = sizeof(client_sin);
	client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
	if(client_sock < 0)
	{
		perror("error accepting client");
	}
}
std::string TCPServer::RecvMSG()
{
	char buffer[4096];
	int expected_data_len = sizeof(buffer);
	int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
	if(read_bytes == 0)
	{
		return "";
	}
	else
	{
		return buffer;
	}
}
void TCPServer::sendAnswer(std::string DATA, int length)
{
	int send_bytes = send(client_sock, DATA.c_str(), length, 0);
	if(send_bytes < 0)
	{
		perror("error sending to client");
	}
}
TCPServer::~TCPServer()
{
	close(sock);
}
