/*
 * student name: Nadav Schweitzer
 * exercise name: ex3
 * file description: professional class
 */
#include "Professional.h"
#include <string>
using namespace std;
/**
 * this function return the id of the professional
 * @return: the id of the professional
 */
string Professional::getId() const
{
	return id;
}
/**
 * this function return the age of the pro
 * @return: the age
 */
int Professional::getAge()
{
	return age;
}
/**
 * this function return the amount of movies of the pro
 * @return: the amount of movies
 */
int Professional::getAmountOfMovies()
{
	return amountOfMovies;
}
/**
 * this function increase the amount of movies
 */
void Professional::IncAmountOfMovies()
{
	amountOfMovies++;
}
/**
 * this function decrease the amount of movies
 */
void Professional::DecAmountOfMovies()
{
	amountOfMovies--;
}
/**
 * this function return the info of the professional
 * @return: the info of the professional
 */
string Professional::getInfo() const
{
	return info;
}
/**
 * this function return if the two professionals are equal
 * @return: true if they are equal and else false
 */
bool Professional::operator==(const Professional& other)
{
	return getId() == other.getId();
}
/**
 * destructor of this class
 */
Professional::~Professional()
{

}
