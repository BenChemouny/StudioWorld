/*
 * UDPServer.h
 *
 *  Created on: Dec 16, 2015
 *      Author: nadav
 */

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
