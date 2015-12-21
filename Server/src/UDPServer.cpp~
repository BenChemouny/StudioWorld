#include "UDPServer.h"
#include "Recv.h"
#include <iostream>
using namespace std;

UDPServer::UDPServer(int port)
{
	this->sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(this->sock < 0)
	{
		perror("error creating socket");
	}
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);

	if(bind(sock,(struct sockaddr*)&sin, sizeof(sin))<0)
	{
		perror("error binding to socket");
	}
}
std::string UDPServer::RecvMSG()
{
	unsigned int from_len = sizeof(struct sockaddr_in);
	char buffer[4096];
	int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&sin, &from_len);
	if(bytes < 0)
	{
		perror("error reading from socket");
	}
	//cout<<"The client sends: "<<buffer<<endl;
	return buffer;
}
void UDPServer::sendAnswer(std::string DATA, int length)
{
	//char buffer[] = "answer";
	int sent_bytes = sendto(sock, DATA.data(), length, 0, (struct sockaddr *)&sin, sizeof(sin));
	if(sent_bytes < 0)
	{
		perror("error writing to socket");
	}
}
UDPServer::~UDPServer()
{
}
