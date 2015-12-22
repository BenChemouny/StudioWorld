#include <iostream>
#include <string>
#include "UDPServer.h"
#include "TCPServer.h"
#include <stdlib.h>
#include "Cinema.h"

using namespace std;

int main(int argc, char *argv[]) {
	if(argc < 3)
	{
		return 1;
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
	Cinema cinema;
	while (true)
	{
	std::string msg = "";
	msg = server->RecvMSG();
	string response = cinema.start(msg);
	server->sendAnswer(response, response.length());
	}
}
