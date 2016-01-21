/*
 * student name: Nadav Schweitzer & Ben Shimoni
 * exercise name: ex4
 * file description: professional class
 */
#ifndef SRC_PROFESSIONAL_H_
#define SRC_PROFESSIONAL_H_
#include <string>
#include "Movie.h"
#include <sstream>
using namespace std;

enum Gender{Male,Female};
//professional class
class Professional
{
protected:
	//the id of the professional
	string id;
	//the name of the professional
	string name;
	//the info of the professional
	string info;
	//the age of the professional
	int age;
	//the gender of the professional
	enum Gender gender;
	//the amount of movies
	int amountOfMovies;
	int type;
public:
	/**
	 * abstract function.
	 * this function print the information of the professional
	 */
	virtual string print() = 0;
	/**
	 * this function return the id of the professional
	 * @return: the id of the professional
	 */
	string exportPro();
	string getId() const;
	/**
	 * this function return the age of the pro
	 * @return: the age
	 */
	int getAge();
	/**
	 * this function return the amount of movies of the pro
	 * @return: the amount of movies
	 */
	int getAmountOfMovies();
	/**
	 * this function increase the amount of movies
	 */
	void IncAmountOfMovies();
	/**
	 * this function decrease the amount of movies
	 */
	void DecAmountOfMovies();
	/**
	 * this function return the info of the professional
	 * @return: the info of the professional
	 */
	string getInfo() const;
	/**
	 * this function return if the two professionals are equal
	 * @return: true if they are equal and else false
	 */
	bool operator==(const Professional& other);
	/**
	 * destructor of this class
	 */
	virtual int getType()=0;
	virtual ~Professional();
};

#endif
