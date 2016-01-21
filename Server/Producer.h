/*
 * student name: Nadav Schweitzer & Ben Shimoni
 * exercise name: ex4
 * file description: producer class
 */
#ifndef SRC_PRODUCER_H_
#define SRC_PRODUCER_H_
#include "Professional.h"
using namespace std;
//producer class
class Producer: public Professional
{
public:
	/**
	 * this constructor gets information about the producer and create a new producer
	 * with the given information
	 * @param id: the id of the producer
	 * @param name: the name of the producer
	 * @param info: the info of the producer
	 * @param age: the age of the producer
	 * @param gender: the gender of the producer
	 * @return: the new producer
	 */
	Producer(string id, string name, string info, int age, enum Gender gender);
	/**
	 * this function print the details about the producer
	 */
	int getType();
	string print();
};

#endif
