/*
 * 8921005	Nadav Schweitzer
		Ben Shimoni
 */
#include <iostream>
#include <string>
#include "TCPServer.h"
#include <stdlib.h>
#include "Cinema.h"
/**
 * program name: ex4
 * the operation: this program is the cinema program using the TCP and UDP protocols
 */
using namespace std;
void *threadfunc(void* data)
{
	return NULL;
}
int main(int argc, char *argv[]) {
	if(argc < 3)
	{
		return -1;
	}
	int user=0;
	Cinema* current;
	string type = string(argv[1]);
	Recv* server;
	if(type == "TCP")
	{
		server = new TCPServer(atoi(argv[2]));
	}
	else
	{
		return -1;
	}
	current = Cinema::getInstance();
	while (user!=0)
	{
	std::string msg = "";
	msg = server->RecvMSG();
	string response = current->start(msg);
	server->sendAnswer(response, response.length());
	}
}
