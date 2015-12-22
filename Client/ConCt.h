/*
 * ConCt.h
 *
 *  Created on: Dec 21, 2015
 *      Author: waeky
 */

#ifndef CONCT_H_
#define CONCT_H_

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <string.h>

class ConCt {
public:
	ConCt();
	 virtual void sendMSG(std::string DATA,int length) =0;
	 virtual void getAnswer()=0;
	 virtual ~ConCt();
protected:
	struct sockaddr_in sin;
	int sock;
	std::string DATA;

};

#endif /* CONCT_H_ */
