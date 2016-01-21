/*
  * student name: Nadav Schweitzer & Ben Shimoni
 * exercise name: ex4
 * file description: director class
 */
#ifndef SRC_DIRECTOR_H_
#define SRC_DIRECTOR_H_
#include "Professional.h"
#include <string>
using namespace std;
//director class
class Director: public Professional
{
public:
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
	Director(string id, string name, string info, int age, enum Gender gender);
	/**
	 * this function print the details about the director
	 */
	int getType();
	string print();
};



#endif
