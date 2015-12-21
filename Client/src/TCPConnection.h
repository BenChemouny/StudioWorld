/*
 * TCPConnection.h
 *
 *  Created on: Dec 21, 2015
 *      Author: waeky
 */

#ifndef TCPCONNECTION_H_
#define TCPCONNECTION_H_

#include "ConCt.h"

class TCPConnection: public ConCt {
public:
	TCPConnection(std::string IP,int port);
	void sendMSG(std::string DATA,int length);
	void getAnswer();
	virtual ~TCPConnection();
};

#endif /* TCPCONNECTION_H_ */
