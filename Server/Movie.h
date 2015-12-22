/*
 * student name: Nadav Schweitzer
 * exercise name: ex3
 * file description: movie class
 */
#ifndef SRC_MOVIE_H_
#define SRC_MOVIE_H_

#include <string>
#include <list>
#include <iostream>
#include "Professional.h"
using namespace std;
class Professional;
enum SortType{ById,ByAge,ByAmountOfMovies};
//movie class
class Movie
{
	//the id of the movie
	string id;
	//the name of the movie
	string name;
	//the length of the movie
	int length;
	//the publish year of the movies
	int publishYear;
	//the rate of the movie
	float rate;
	//the summary of the movie
	string summary;
	//the professionals list of the movie
	list<Professional*> professionals;
	//the sort type of the movie
	enum SortType sortType;
	//the list of the genres of the movie
	list<string> genres;
	std::string outp;
public:
	void emptyOutp();
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
	Movie(string id, string name, int length, int publishYear, float rate, string summary);
	/**
	 * this function gets a professional and add it to the movie
	 * @param p: the professional to add
	 */
	int addProfessional(Professional* p);
	/**
	 * this function gets a professional id and delete it from the movie
	 * @param id: the id of the professional to delete
	 */
	void deleteProfessional(Professional* pro);
	/**
	 * this function print the information about the movie
	 */
	string print();
	/**
	 * this function print all the professionals of this movie
	 */
	string printProfessionals();
	/**
	 * this function gets a genre and add it to the movie
	 * @param genre: the genre to add
	 */
	void addGenre(string genre);
	/**
	 * this functoin print all the genres of this movie
	 */
	string printGenres();
	/**
	 * this function gets a movie and merge it to this movie
	 * @param m: the movie to merge
	 * @return: the merged movie
	 */
	Movie* operator+(Movie m);
	/**
	 * this function return the id of the movie
	 * @param id: the id of the movie
	 */
	string getId();
	/**
	 * this function return the name of the movie
	 * @param name: the name of the movie
	 */
	string getName();
	/**
	 * this function return the length of the movie
	 * @param length: the length of the movie
	 */
	int getLength();
	/*
	 * this function return the publish year
	 * @return: the publish year
	 */
	int getPublishYear();
	/*
	 * this function return the rate
	 * @return: the rate
	 */
	float getRate();
	/**
	 * this function return the list of the professionals of the movie
	 * @return: the list of the professionals
	 */
	list<Professional*> getProfessionals();
	/**
	 * this function gets a sort type and set the sort type of the movie
	 * @param sortType: the sort type to set
	 */
	void setSortType(enum SortType sortType);
	/**
	 * this function return the sort type of the movie
	 * @return: the sort type of the movie
	 */
	enum SortType getSortType();
	/*
	 * this function return the genres
	 * @return: the genres
	 */
	list<string> getGenres();
	/**
	 * this function gets id and check if the movie has the pro
	 * @param pId: the id of the pro
	 * @return: 1 if the movie has the pro or 0 if not
	 */
	int hasProfessional(string pId);
	/**
	 * this function sort the professional by the sort type
	 */
	void sortProfessionals();
};

#endif
