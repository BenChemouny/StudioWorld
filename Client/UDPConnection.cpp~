/*
 * UDPConnection.cpp
 *
 *  Created on: Dec 21, 2015
 *      Author: waeky
 */
using namespace std;
#include "UDPConnection.h"
#include "ConCt.h"
#include <iostream>

UDPConnection::UDPConnection(std::string Ip,int Port) {
	this->sock = socket(AF_INET, SOCK_DGRAM, 0);
	this->DATA = "";
    memset(&this->sin, 0, sizeof(this->sin));
    this->sin.sin_family = AF_INET;
    this->sin.sin_addr.s_addr = inet_addr(Ip.data());
    this->sin.sin_port = htons(Port);
}
void UDPConnection::sendMSG(std::string DATA,int length)
{
    int sent_bytes = sendto(this->sock, DATA.data(), length, 0, (struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
}
void UDPConnection::getAnswer(){
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096];
    memset(&buffer, 0, sizeof(buffer));
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("error reading from socket");
    }
    cout << buffer;
}
UDPConnection::~UDPConnection() {
	// TODO Auto-generated destructor stub
}

