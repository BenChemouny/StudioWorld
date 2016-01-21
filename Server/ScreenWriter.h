/*
 * student name: Nadav Schweitzer & Ben Shimoni
 * exercise name: ex4
 * file description: screen writer class
 */
#ifndef SRC_SCREENWRITER_H_
#define SRC_SCREENWRITER_H_
#include "Professional.h"
using namespace std;
//screen writer class
class ScreenWriter: public Professional
{
public:
	/**
	 * this constructor gets information about the screen writer and create a new
	 * screen writer
	 * with the given information
	 * @param id: the id of the screen writer
	 * @param name: the name of the screen writer
	 * @param info: the info of the screen writer
	 * @param age: the age of the screen writer
	 * @param gender: the gender of the screen writer
	 * @return: the new screen writer
	 */
	ScreenWriter(string id, string name, string info, int age, enum Gender gender);
	/**
	 * this function print the details about the screen writer
	 */
	int getType();
	string print();
};

#endif
