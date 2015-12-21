#include <iostream>
#include <string>
#include "UDPServer.h"
#include "TCPServer.h"
#include <stdlib.h>

/****************************************
* Student Name: Nadav and Ben            *
* Exercise Name:  EX-4              *
* File description:  Server.cpp              *
****************************************/
using namespace std;

int main(int argc, char *argv[]) {
	if(argc < 3)
	{
		return -1;
	}
	string type = string(argv[1]);
	Recv* server;
	if(type == "TCP")
	{
		server = new TCPServer(atoi(argv[2]));
	}
	else if(type == "UDP")
	{
		server = new UDPServer(atoi(argv[2]));
	}
	else
	{
		return -1;
	}
	while (true)
	{
	std::string msg = "";
	msg = server->RecvMSG();
	server->sendAnswer(msg, msg.length());
	}
}
