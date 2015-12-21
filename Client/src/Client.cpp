//============================================================================
// Name        : Client.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
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
		return 1;

	cout << "Hello, and Welcome to the Studio. (" << type << ") Edition !!"<<"\n \n" << endl;
	while(command!="-1")
	{
		std::getline(std::cin, command);
		Conn->sendMSG(command+"\0",command.length()+1);
		Conn->getAnswer();
	}
	return 1;
}
