/*
 * student name: Nadav Schweitzer & Ben Shimoni
 * exercise name: ex4
 * file description: TCPServer class
 */
#ifndef SERVEROOP_TCPSERVER_H_
#define SERVEROOP_TCPSERVER_H_
#include "Recv.h"
#include <string>

class TCPServer: public Recv {
protected:
	//the socket of the client
	int client_sock;
	//the socket of the server
	int sock;
public:
	/*
	* this is the constructor of the tcpServer class
	* @param port: the port that the server will listen to
	*/
	TCPServer(int port);
	int WaitForClient();
	/*
	* this function recive the message from the client and return it
	* @return: the message
	*/
	std::string RecvMSG(int clientSock);
	/*
	* this function send a message to the client
	* @param DATA: the message to send
	* @param length: the length of the message
	*/
	void sendAnswer(std::string DATA, int length, int clientSock);
	/*
	* the destructor of the class, close the socket
	*/
	virtual ~TCPServer();
};




#endif
