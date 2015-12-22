/****************************************
* Student Name: Nadav and Ben            *
* Exercise Name:  EX-4              *
* File description:  ConCt.h              *
****************************************/

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
	//Constructor for the virtual class ConCt;
	ConCt();
	/******************************************
	* sendMsg get a message to send (as a string) and its length *
	* and sends it out accourding to the selected protocol (TCP/UDP) *	
	*******************************************/
	 virtual void sendMSG(std::string DATA,int length) =0;
	/******************************************
	* getAnswer uses the resvfrom and resv fuctions to get any user *
	* messages with the the selected protocol (TCP/UDP) and print it on-screen *	
	*******************************************/
	 virtual void getAnswer()=0;
	// destructor of ConCt
	 virtual ~ConCt();
protected:
	struct sockaddr_in sin; //struct for Internet Address.
	int sock; //the socket.
};

#endif /* CONCT_H_ */
