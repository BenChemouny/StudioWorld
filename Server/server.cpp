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
 * program name: ex4
 * the operation: this program is the cinema program using the TCP and UDP protocols
 */
using namespace std;
struct S_Data {
	int sock;
	Recv* server;
};
void *threadfunc(void* data)
{
	S_Data sdata = *((S_Data*)data);
	int clientSock = sdata.sock;
	cout<<"thread started "<<clientSock<<endl;
	Recv* server = sdata.server;
	Cinema* current = Cinema::getInstance();
	cout<<"got singleton"<<endl;
	while (true)
	{
		cout<<"waiting "<<clientSock<<endl;
		std::string msg = "";
		msg = server->RecvMSG(clientSock);
		if(!strcmp(msg.c_str(),"-1"))
			break;
		string response = current->start(msg);
		server->sendAnswer(response, response.length(), clientSock);
	}
}
int main(int argc, char *argv[]) {
	cout<<"start"<<endl;
	if(argc < 3)
	{
		return -1;
	}
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
	cout<<"..."<<endl;
	current = Cinema::getInstance();
	cout<<"instance"<<endl;
	//list<pthread_t> threads;
	int clientSock;
	while(true)
	{
		pthread_t thread;
		S_Data data;
		cout<<"wait for client"<<endl;
		clientSock = server->WaitForClient(atoi(argv[2]));
		cout<<"got client"<<endl;
		data.sock = clientSock;
		data.server = server;
		int status = pthread_create(&thread, NULL, threadfunc, (void*)&data);
		cout<<"open thread "<<status<<endl;
		if(status)
		{
			//error("error with he thread");
		}
		//threads.push_back(thread);
	}

}
