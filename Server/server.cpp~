/*
 * 8921005	Nadav Schweitzer
		Ben Shimoni
 */
#include <iostream>
#include <string>
#include "TCPServer.h"
#include <stdlib.h>
#include "Cinema.h"
#include <pthread.h>
/**
 * program name: ex5
 * the operation: this program is the cinema program using the TCP and UDP protocols
 */
using namespace std;
struct S_Data {
	int sock;
	Recv* server;
};
/**
 * this function handle one client
 * @param data: the data about the client
 */
void *threadfunc(void* data)
{
	//retrive the data
	S_Data sdata = *((S_Data*)data);
	//get the client sock
	int clientSock = sdata.sock;
	//get the data about the server
	Recv* server = sdata.server;
	while (true)
	{
		//get the message from the client
		std::string msg = "";
		msg = server->RecvMSG(clientSock);
		//if the client is closed we end the function
		if(!strcmp(msg.c_str(),""))
		{
			break;
		}
		//get the most updated cinema instance
		Cinema* current = Cinema::getInstance();
		string response = current->start(msg);
		//send the answer to the client
		server->sendAnswer(response, response.length(), clientSock);
	}
}
int main(int argc, char *argv[]) {
	//if we dont have enough args we return -1
	if(argc < 3)
	{
		return -1;
	}
	Cinema* current;
	string type = string(argv[1]);
	Recv* server;
	//check that we are using TCP
	if(type == "TCP")
	{
		server = new TCPServer(atoi(argv[2]));
	}
	else
	{
		return -1;
	}
	int clientSock;
	//the server listen for clients
	while(true)
	{
		pthread_t thread;
		S_Data data;
		//wait for a client to connect
		clientSock = server->WaitForClient(atoi(argv[2]));
		//if a client is trying to connect we open a thread that will handle
		//him
		data.sock = clientSock;
		data.server = server;
		int status = pthread_create(&thread, NULL, threadfunc, (void*)&data);
		//if there was an error we print a message
		if(status)
		{
			cout<<"error!!!"<<endl;
		}
	}
}
