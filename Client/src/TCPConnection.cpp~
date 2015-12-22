/*
 * TCPConnection.cpp
 *
 *  Created on: Dec 21, 2015
 *      Author: waeky
 */
using namespace std;
#include "TCPConnection.h"
#include "ConCt.h"
#include <iostream>

TCPConnection::TCPConnection(std::string Ip,int Port) {
	this->sock = socket(AF_INET, SOCK_STREAM, 0);
	this->DATA = "";
    memset(&this->sin, 0, sizeof(this->sin));
    this->sin.sin_family = AF_INET;
    this->sin.sin_addr.s_addr = inet_addr(Ip.data());
    this->sin.sin_port = htons(Port);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
            perror("error connecting to server");
        }
}
void TCPConnection::sendMSG(std::string DATA,int length)
{
	int sent_bytes = send(sock, DATA.data(), length, 0);
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
}
string TCPConnection::getAnswer(){
	char buffer[4096];
	int expected_data_len = sizeof(buffer);
	int read_bytes = recv(sock, buffer, expected_data_len, 0);
	    if (read_bytes == 0) {
	    	perror("end of transmition");
	    }
	    else if (read_bytes < 0) {
	    	perror("error reading from socket");
	    }
	return buffer;
}
TCPConnection::~TCPConnection() {
	// TODO Auto-generated destructor stub
}

