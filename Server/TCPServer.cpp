/*
 * student name: Nadav Schweitzer & Ben Shimoni
 * exercise name: ex4
 * file description: TCPServer class
 */
#include "TCPServer.h"
#include "Recv.h"
#include <iostream>
using namespace std;

/*
* this is the constructor of the tcpServer class
* @param port: the port that the server will listen to
*/
TCPServer::TCPServer(int port)
{
	cout<<"tcp"<<endl;
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


	cout<<"waitfor"<<endl;
	if(listen(sock, 5) < 0)
	{
		perror("error listening to a socket");
	}
	/*if(listen(sock, 5) < 0)
	{
		perror("error listening to a socket");
	}
	struct sockaddr_in client_sin;
	unsigned int addr_len = sizeof(client_sin);
	client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
	if(client_sock < 0)
	{
		perror("error accepting client");
	}*/
}
int TCPServer::WaitForClient(int port)
{
	struct sockaddr_in client_sin;
	unsigned int addr_len = sizeof(client_sin);
	cout<<"listen "<<sock<<endl;
	client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
	cout<<"accept"<<endl;
	if(client_sock < 0)
	{
		perror("error accepting client");
	}
	return client_sock;
}
/*
* this function recive the message from the client and return it
* @return: the message
*/
std::string TCPServer::RecvMSG(int clientSock)
{
	char buffer[4096];
	memset(&buffer, 0, sizeof(buffer));
	int expected_data_len = sizeof(buffer);
	int read_bytes = recv(clientSock, buffer, expected_data_len, 0);
	if(read_bytes == 0)
	{
		return "";
	}
	else
	{
		return buffer;
	}
}
/*
* this function send a message to the client
* @param DATA: the message to send
* @param length: the length of the message
*/
void TCPServer::sendAnswer(std::string DATA, int length, int clientSock)
{
	int send_bytes = send(clientSock, DATA.c_str(), length, 0);
	if(send_bytes < 0)
	{
		perror("error sending to client");
	}
}
/*
* the destructor of the class, close the socket
*/
TCPServer::~TCPServer()
{
	close(sock);
}
