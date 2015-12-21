/*
 * UDPServer.h
 *
 *  Created on: Dec 16, 2015
 *      Author: nadav
 */
/****************************************
* Student Name: Nadav and Ben            *
* Exercise Name:  EX-4              *
* File description:  UDPServer.h              *
****************************************/
#ifndef UDPSERVER_H_
#define UDPSERVER_H_
#include "Recv.h"
#include <string>

class UDPServer: public Recv {
public:
	UDPServer(int port);
	std::string RecvMSG();
	void sendAnswer(std::string DATA, int length);
	virtual ~UDPServer();
};




#endif /* UDPSERVER_H_ */
