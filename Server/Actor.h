/*
 * student name: Nadav Schweitzer
 * exercise name: ex3
 * file description: actor class
 */
#ifndef SRC_ACTOR_H_
#define SRC_ACTOR_H_
#include "Professional.h"
using namespace std;
//actor class
class Actor: public Professional
{
public:
	/**
	 * empty constructor - create a new actor
	 */
	Actor();
	/**
	 * constructor - create a new actor with this information
	 * @param id: the id of the actor
	 * @param name: the name of the actor
	 * @param info: the info of the actor
	 * @param age: the age of the actor
	 * @param gender: the gender of the actor
	 * @return: the new actor
	 */
	Actor(string id, string name, string info, int age, enum Gender gender);
	/**
	 * print the actor info to the screen
	 */
	void print();
	/**
	 * destructor of actor
	 */
	~Actor();
};

#endif
