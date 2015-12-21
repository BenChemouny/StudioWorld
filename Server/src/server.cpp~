#include <iostream>
#include <string>
#include "UDPServer.h"
#include <stdlib.h>

using namespace std;

int main(int argc, char * argv[]) {
	Recv* server = new UDPServer(atoi(argv[1]));

	server->RecvMSG();
	server->sendAnswer("success",7);
}
