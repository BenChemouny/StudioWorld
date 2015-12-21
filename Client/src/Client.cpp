//============================================================================
// Name        : Client.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "UDPConnection.h"
#include <string>

int main(int argc, char * argv[]) {
	std::string MSG = "Hello, its ME";
	std::string IP = "192.168.8.139";
	UDPConnection conn(argv[0],55555);
	conn.sendMSG(MSG,MSG.length());
	conn.getAnswer();
}
