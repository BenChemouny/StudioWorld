/*
 * 8921005 *** Nadav Schweitzer
 */
#include <iostream>
#include "Cinema.h"
/**
 * program name: ex3
 * the operation: this program is a unit test that test
 * the classes
 */
int main(int argc, char* argv[])
{
	Cinema cinema;
	string msg = "1 asd name 160 2012 5.7 info2";
	cinema.start(msg);
	msg = "1 dsa name 150 2010 5.5 info";
	cinema.start(msg);
	msg = "8 asd,dsa";
	cinema.start(msg);
	msg = "13";
	cinema.start(msg);
	return 0;
}
