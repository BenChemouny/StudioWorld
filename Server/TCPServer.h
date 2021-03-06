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
	/*
	* Listens the the port and awaits incoming clients.
	* @return client_sock : the socket that the server received from a client
	*/
	int WaitForClient(int port);
	/*
	* this function recive the message from the client and return it
	* @param clientSock to which the thread waits for user input.
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
