/*
 * TCPServer.h
 *
 *  Created on: Dec 21, 2015
 *      Author: nadav
 */

#ifndef SERVEROOP_TCPSERVER_H_
#define SERVEROOP_TCPSERVER_H_
#include "Recv.h"
#include <string>

class TCPServer: public Recv {
protected:
	int client_sock;
	int sock;
public:
	TCPServer(int port);
	std::string RecvMSG();
	void sendAnswer(std::string DATA, int length);
	virtual ~TCPServer();
};




#endif /* SERVEROOP_TCPSERVER_H_ */
