/*
 * student name: Nadav Schweitzer & Ben Shimoni
 * exercise name: ex4
 * file description: director class
 */
#include "Director.h"
#include <string>
using namespace std;
/**
 * this constructor gets information about the director and create a new director
 * with the given information
 * @param id: the id of the director
 * @param name: the name of the director
 * @param info: the info of the director
 * @param age: the age of the director
 * @param gender: the gender of the director
 * @return: the new director
 */
Director::Director(string id, string name, string info, int age, enum Gender gender)
{
	this->id = id;
	this->name = name;
	this->info = info;
	this->age = age;
	this->gender = gender;
	this->amountOfMovies = 0;
}
/**
 * this function print the details about the director
 */
string Director::print()
{
	return name;
}
