/****************************************
* Student Name: Nadav and Ben            *
* Exercise Name:  EX-4              *
* File description:  UDPConnection.h              *
****************************************/
#ifndef UDPCONNECTION_H_
#define UDPCONNECTION_H_

#include "ConCt.h"
#include <string>

class UDPConnection: public ConCt {
public:
	UDPConnection(std::string Ip,int Port); //Constructor for the connection : gets IP/PORT
	/******************************************
	* sendMsg get a message to send (as a string) and its length *
	* and sends it out accourding to the UDP Protocol *	
	*******************************************/
	void sendMSG(std::string DATA,int length);
	/******************************************
	* getAnswer uses the recvfrom fuction to get any server *
	* messages with the the UDP protocol and print it on-screen *	
	*******************************************/
	void getAnswer();
	virtual ~UDPConnection(); //Destructor
};

#endif /* UDPCONNECTION_H_ */
