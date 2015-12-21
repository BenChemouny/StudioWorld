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
	string command;
	if(argc>4) { cout << "missing args" ; return 0 ; }
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
	std::getline(std::cin, command);
	if(command=="-1") return 1;
	else
	{
		Conn->sendMSG(command,command.length());
		Conn->getAnswer();
	}
}
