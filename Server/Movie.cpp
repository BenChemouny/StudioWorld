/*
 * student name: Nadav Schweitzer & Ben Shimoni
 * exercise name: ex4
 * file description: movie class
 */
#include "Movie.h"
#include <string>
#include <string.h>
#include <list>
#include <sstream>
using namespace std;

void Movie::emptyOutp()
{
	this->outp = "";
}
/**
 * the constructor of the movie class
 * the function gets the information of the movie and return a new movie
 * @param id: the id of the movie
 * @param name: the name of the movie
 * @param length: the length of the movie
 * @param publishYear: the publish year of the movie
 * @param rate: the rate of the movie
 * @param summary: the summary of the movie
 * @return: the new movie
 */
Movie::Movie(string id, string name, int length, int publishYear, float rate, string summary)
{
	this->id = id;
	this->name = name;
	this->length = length;
	this->publishYear = publishYear;
	this->rate = rate;
	this->summary = summary;
	this->outp = "";
}
/**
 * this function gets a professional and add it to the movie
 * @param p: the professional to add
 */
int Movie::addProfessional(Professional *p)
{
	list<Professional*>::iterator it;
	for(it = professionals.begin(); it != professionals.end(); it++)
	{
		if(!strcmp((*it)->getId().c_str(),p->getId().c_str()))
		{
			return 0;
		}
	}
	professionals.push_back(p);
	return 1;
}
/**
 * this function gets a professional id and delete it from the movie
 * @param id: the id of the professional to delete
 */
void Movie::deleteProfessional(Professional* pro)
{
	list<Professional*>::iterator it;
	for(it = professionals.begin(); it != professionals.end(); it++)
	{
		if((*it)->getId() == pro->getId())
		{
			professionals.remove(*it);
			break;
		}
	}
}
/**
 * this function print the information about the movie
 */
string Movie::print()
{
	this->outp="";
	stringstream convert1;
	stringstream convert2;
	stringstream convert3;
	convert1<<length;
	string sLength = convert1.str();
	convert2<<publishYear;
	string sPublishYear = convert2.str();
	convert3<<rate;
	string sRate = convert3.str();
	outp += id + " "+ name + " " + sLength + " "+ sPublishYear+ " "+ sRate+ " ";
	outp += printGenres();
	outp += summary + "\n";
	printProfessionals();
	return outp;
}
string Movie::exportMovie()
{
	this->outp="";
	stringstream convert1;
	stringstream convert2;
	stringstream convert3;
	convert1<<length;
	string sLength = convert1.str();
	convert2<<publishYear;
	string sPublishYear = convert2.str();
	convert3<<rate;
	string sRate = convert3.str();
	outp += id + " "+ name + " " + sLength + " "+ sPublishYear+ " "+ sRate+ " ";
	outp += printGenres();
	outp += summary + "\n";
	sortProfessionals();
	list<Professional*>::iterator it;
	for(it = professionals.begin(); it != professionals.end(); it++)
	{
		outp += (*it)->getId();
		outp += ",";
	}
	return outp;
}
/**
 * this function print all the professionals of this movie
 */
string Movie::printProfessionals()
{
	sortProfessionals();
	list<Professional*>::iterator it;
	for(it = professionals.begin(); it != professionals.end(); it++)
	{
		outp += (*it)->print();
		outp += "\n";
	}
	return outp;
}
/**
 * this function gets a genre and add it to the movie
 * @param genre: the genre to add
 */
void Movie::addGenre(string genre)
{
	genres.push_back(genre);
}
/**
 * this functoin print all the genres of this movie
 */
string Movie::printGenres()
{
	string outp = "";
	if(genres.begin() != genres.end())
	{
		list<string>::iterator it;
		for(it = genres.begin(); it != genres.end(); it++)
		{
			outp += *it;
			if((++it)!=genres.end())
			{
				outp += ",";
			}
			--it;
		}
		outp += " ";
	}
	return outp;
}
/**
 * this function gets a movie and merge it to this movie
 * @param m: the movie to merge
 * @return: the merged movie
 */
Movie* Movie::operator+(Movie m)
{
	string id;
	string name;
	int length;
	int publishYear;
	float rate;
	string summary;
	Movie* newMovie;

	list<string>::iterator genresIt;
	list<Professional*>::iterator prosIt;

	list<string> genres;
	list<Professional*> pros;
	//get the genres and the pros from the first movie
	list<string> currentGenres = this->getGenres();
	for(genresIt = currentGenres.begin(); genresIt != currentGenres.end(); genresIt++)
	{
		genres.push_back(*genresIt);
	}
	currentGenres = m.getGenres();
	for(genresIt = currentGenres.begin(); genresIt != currentGenres.end(); genresIt++)
	{
		list<string>::iterator it;
		int exist = 0;
		for(it = genres.begin(); it != genres.end(); it++)
		{
			if(!strcmp((*it).c_str(),(*genresIt).c_str()))
			{
				exist = 1;
				break;
			}
		}
		if(!exist)
		{
			genres.push_back(*genresIt);
		}
	}
	//get the data from the second movie and check to not copy the pro or genre
	//twice
	list<Professional*> currentPros = this->getProfessionals();
	for(prosIt = currentPros.begin(); prosIt != currentPros.end(); prosIt++)
	{
		pros.push_back(*prosIt);
	}
	currentPros = m.getProfessionals();
	for(prosIt = currentPros.begin(); prosIt != currentPros.end(); prosIt++)
	{
		list<Professional*>::iterator it;
		int exist = 0;
		for(it = pros.begin(); it != pros.end(); it++)
		{
			if(!strcmp((*it)->getId().c_str(),(*prosIt)->getId().c_str()))
			{
				exist = 1;
				break;
			}
		}
		if(!exist)
		{
			pros.push_back(*prosIt);
		}
	}
	//generate the id
	id = this->getId();
	id += "_";
	id += m.getId();
	//get the data from the longer movie
	if(this->length >= m.length)
	{
		name = this->getName();
		length = this->getLength();
		publishYear = this->publishYear;
		rate = this->rate;
		summary = this->summary;
	}
	else
	{
		name = m.name;
		length = m.length;
		publishYear = m.publishYear;
		rate = m.rate;
		summary = m.summary;
	}
	//make the new movie
	newMovie = new Movie(id, name, length, publishYear, rate, summary);
	newMovie->setSortType(ById);
	//add the genres and pros
	for(genresIt = genres.begin(); genresIt != genres.end(); genresIt++)
	{
		newMovie->addGenre(*genresIt);
	}
	for(prosIt = pros.begin(); prosIt != pros.end(); prosIt++)
	{
		newMovie->addProfessional(*prosIt);
	}
	//return the new movie
	return newMovie;
}
/**
 * this function return the id of the movie
 * @param id: the id of the movie
 */
string Movie::getId()
{
	return id;
}
/**
 * this function return the name of the movie
 * @param name: the name of the movie
 */
string Movie::getName()
{
	return name;
}
/**
 * this function return the length of the movie
 * @param length: the length of the movie
 */
int Movie::getLength()
{
	return length;
}
/*
 * this function return the publish year
 * @return: the publish year
 */
int Movie::getPublishYear()
{
	return publishYear;
}
/*
 * this function return the rate
 * @return: the rate
 */
float Movie::getRate()
{
	return rate;
}
/**
 * this function return the list of the professionals of the movie
 * @return: the list of the professionals
 */
list<Professional*> Movie::getProfessionals()
{
	return professionals;
}
/**
 * this function gets a sort type and set the sort type of the movie
 * @param sortType: the sort type to set
 */
void Movie::setSortType(enum SortType sortType)
{
	this->sortType = sortType;
}
/**
 * this function return the sort type of the movie
 * @return: the sort type of the movie
 */
enum SortType Movie::getSortType()
{
	return sortType;
}
/*
 * this function return the genres
 * @return: the genres
 */
list<string> Movie::getGenres()
{
	return genres;
}
/**
 * this function gets id and check if the movie has the pro
 * @param pId: the id of the pro
 * @return: 1 if the movie has the pro or 0 if not
 */
int Movie::hasProfessional(string pId)
{
	list<Professional*>::iterator prosIt;
	for(prosIt = professionals.begin(); prosIt != professionals.end(); prosIt++)
	{
		if(!strcmp((*prosIt)->getId().c_str(),pId.c_str()))
		{
			return 1;
		}
	}
	return 0;
}
/*
 * compare the pros by the id
 * @param p1: the first pro
 * @paeam p2: the second pro
 * @return: if the first smaller than the second
 */
bool compareById(Professional* p1, Professional* p2)
{
	return strcmp(p1->getId().c_str(),p2->getId().c_str()) == -1;
}
/*
 * compare the pros by the age
 * @param p1: the first pro
 * @paeam p2: the second pro
 * @return: if the first larger than the second
 */
bool compareByAge(Professional* p1, Professional* p2)
{
	return p1->getAge() > p2->getAge();
}
/*
 * compare the pros by amount of movies
 * @param p1: the first pro
 * @paeam p2: the second pro
 * @return: if the first larger than the second
 */
bool compareByAmountOfMovies(Professional* p1, Professional* p2)
{
	return p1->getAmountOfMovies() > p2->getAmountOfMovies();
}
/**
 * this function sort the professional by the sort type
 */
void Movie::sortProfessionals()
{
	switch(sortType)
	{
	case ById:
		professionals.sort(compareById);
		break;
	case ByAge:
		professionals.sort(compareByAge);
		break;
	case ByAmountOfMovies:
		professionals.sort(compareByAmountOfMovies);
		break;
	default:
		break;
	}
}
