/****************************************
* Student Name: Nadav and Ben            *
* Exercise Name:  EX-4              *
* File description:  Client.cpp              *
****************************************/
using namespace std;
#include <iostream>
#include "UDPConnection.h"
#include "TCPConnection.h"
#include <string>
#include <stdlib.h>
/*********************************************************************
* Program name:   Client  *
* The operation:  The main function receive three arguments the protocol the IP and the port.			*
* According to the first arguments we initialize the proper protocol,						*
* with the second and third argument representing the IP address and the port					*
* When the function gets a line from the user and sends it to the server in the previously determined protocol	*
* and then receive the server's answer and it's ready to input another line                               	*    
*********************************************************************/

int main(int argc, char *argv[]) {
	string command=" ";
	if(argc<4) { cout << "missing args" ; return 1 ; }
	string type = string(argv[1]);
	string IP = string(argv[2]);
	int Port = atoi(argv[3]);
	ConCt* Conn;
	if(type == "TCP")
	{
		Conn = new TCPConnection(IP,Port);
	}
	else if (type =="UDP")
	{
		Conn = new UDPConnection(IP,Port);
	}
	else
	{
		return 1;
	}
	std::getline(std::cin, command);	
	while(command!="-1")
	{
		Conn->sendMSG(command,command.length());
		Conn->getAnswer();
		std::getline(std::cin, command);
	}
	return 1;
}
