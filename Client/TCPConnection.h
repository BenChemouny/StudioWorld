/****************************************
* Student Name: Nadav and Ben            *
* Exercise Name:  EX-4              *
* File description:  TCPConnection.h              *
****************************************/

#ifndef TCPCONNECTION_H_
#define TCPCONNECTION_H_

#include "ConCt.h"
#include <string>

class TCPConnection: public ConCt {
public:
	
	TCPConnection(std::string Ip,int Port); //Constructor for the connection : gets IP/PORT
	/******************************************
	* sendMsg get a message to send (as a string) and its length *
	* and sends it out accourding to the TCP Protocol *	
	*******************************************/
	void sendMSG(std::string DATA,int length);
	/******************************************
	* getAnswer uses the  resv fuction to get any server *
	* messages with the the TCP protocol and print it on-screen *	
	*******************************************/
	void getAnswer();
	virtual ~TCPConnection(); //Destructor
};

#endif /* TCPCONNECTION_H_ */
