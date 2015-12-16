/*
 * student name: Nadav Schweitzer
 * exercise name: ex3
 * file description: screen writer class
 */
#include "ScreenWriter.h"
#include <string>
using namespace std;
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
ScreenWriter::ScreenWriter(string id, string name, string info, int age, enum Gender gender)
{
	this->id = id;
	this->name = name;
	this->info = info;
	this->age = age;
	this->gender = gender;
	this->amountOfMovies = 0;
}
/**
 * this function print the details about the screen writer
 */
void ScreenWriter::print()
{
	cout<<name<<" "<<info<<endl;
}
