/*
 * student name: Nadav Schweitzer & Ben Shimoni
 * exercise name: ex4
 * file description: actor class
 */
#include "Actor.h"
#include <string>
#include <sstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
/**
 * this is the empty constructor of Actor class
 */
Actor::Actor()
{

}
/**
 * this constructor gets information about the actor and create a new actor
 * with the given information
 * @param id: the id of the actor
 * @param name: the name of the actor
 * @param info: the info of the actor
 * @return: the new actor
 */
Actor::Actor(string id, string name, string info, int age, enum Gender gender)
{
	this->id = id;
	this->name = name;
	this->info = info;
	this->age = age;
	this->gender = gender;
	this->amountOfMovies = 0;
}
/**
 * this function print the information of the actor to the screen
 */
string Actor::print()
{
	stringstream convert;
	convert << age;
	string sAge = convert.str();
	return name + " " + sAge;
}
/**
 * this is the destructor of the actor
 */
Actor::~Actor()
{

}
