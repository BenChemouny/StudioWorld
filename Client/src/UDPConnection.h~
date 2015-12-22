/*
 * UDPConnection.h
 *
 *  Created on: Dec 21, 2015
 *      Author: waeky
 */

#ifndef UDPCONNECTION_H_
#define UDPCONNECTION_H_

#include "ConCt.h"
#include <string>

class UDPConnection: public ConCt {
public:
	UDPConnection(std::string Ip,int Port);
	void sendMSG(std::string DATA,int length);
	void getAnswer();
	virtual ~UDPConnection();
};

#endif /* UDPCONNECTION_H_ */
