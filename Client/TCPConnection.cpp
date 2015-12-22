/****************************************
* Student Name: Nadav and Ben            *
* Exercise Name:  EX-4              *
* File description:  TCPConnection.cpp              *
****************************************/
using namespace std;
#include "TCPConnection.h"
#include "ConCt.h"
#include <iostream>
/******************************************
* The Constructor creates the connection *
* Initiallizing the socket, build the Internet *
* Struct and trying to connect to the server - handShake *	
*******************************************/
TCPConnection::TCPConnection(std::string Ip,int Port) {
	this->sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&this->sin, 0, sizeof(this->sin));
    this->sin.sin_family = AF_INET;
    this->sin.sin_addr.s_addr = inet_addr(Ip.data());
    this->sin.sin_port = htons(Port);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
            perror("error connecting to server");
        }
}
/******************************************
* sendMsg get a message to send (as a string) and its length *
* and sends it out accourding to the TCP Protocol *	
*******************************************/
void TCPConnection::sendMSG(std::string DATA,int length)
{
	int sent_bytes = send(sock, DATA.data(), length, 0);
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
}
/******************************************
* getAnswer uses the recv fuction to get any server *
* messages with the the TCP protocol and print it on-screen *	
*******************************************/
void TCPConnection::getAnswer(){
	char buffer[4096];
	memset(&buffer, 0, sizeof(buffer));
	int expected_data_len = sizeof(buffer);
	int read_bytes = recv(sock, buffer, expected_data_len, 0);
	    if (read_bytes == 0) {
	    	perror("end of transmition");
	    }
	    else if (read_bytes < 0) {
	    	perror("error reading from socket");
	    }
	cout << buffer;
}
TCPConnection::~TCPConnection() {
	close(sock);
}

