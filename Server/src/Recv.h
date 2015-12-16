/*
 * Recv.h
 *
 *  Created on: Dec 16, 2015
 *      Author: nadav
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

class Recv {
public:
	Recv();
	virtual void RecvMSG() = 0;
	virtual void sendAnswer(std::string DATA, int length) = 0;
	virtual ~Recv();
protected:
	struct sockaddr_in sin;
	int sock;
	std::string DATA;
};



#endif /* RECV_H_ */
