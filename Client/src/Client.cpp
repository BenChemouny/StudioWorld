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

int main() {
	std::string MSG = "Hello, its ME";
	UDPConnection conn("localhost",5555);
	conn.sendMSG(MSG,MSG.length());
	conn.getAnswer();
}
