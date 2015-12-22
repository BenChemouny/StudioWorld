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
