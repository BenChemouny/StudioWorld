/*
 * student name: Nadav Schweitzer & Ben Shimoni
 * exercise name: ex4
 * file description: Recv class
 */
#ifndef RECV_H_
#define RECV_H_

#include <sys/socket.h>
#include <iostream>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string>
//base server class
class Recv {
public:
	//constructor
	Recv();
	//recive the message from the client
	virtual std::string RecvMSG(int clientSock) = 0;
	//send message to the client
	virtual void sendAnswer(std::string DATA, int length, int clientSock) = 0;
	virtual int WaitForClient(int port) = 0;
	//destructor
	virtual ~Recv();
protected:
	//the socket address input
	struct sockaddr_in sin;
	//the socket
	int sock;
	//the data
	std::string DATA;
};

#endif
