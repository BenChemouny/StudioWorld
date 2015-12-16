/*
 * student name: Nadav Schweitzer
 * exercise name: ex3
 * file description: cinema class
 */
#ifndef SRC_CINEMA_H_
#define SRC_CINEMA_H_
#include <list>
#include <string>
#include <iostream>
#include "Professional.h"
#include "Movie.h"
//Cinema class
class Cinema
{
	//this list holds all the movies
	list<Movie*> movies;
	//this list holds all the professionals
	list<Professional*> professionals;
public:
	/**
	 * empty constructor of cinema class
	 */
	Cinema();
	/*
	 * this function start the program itself and wait for the user to type data
	 */
	void start();
	/*
	 * this function scan for an input until the \n char
	 * @return: the input as a string
	 */
	string scanInput();
	/**
	 * this function scan a movie from the screen and return it
	 * @return: the new movie that we scanned
	 */
	Movie* scanMovie();
	/**
	 * this function scan a professional from the screen and return it
	 * @return: the new professional that we scanned
	 */
	Professional* scanProfessional();
	/**
	 * this function gets a new movie and add it to the movies list
	 * @param m: the new movie to add
	 */
	int addNewMovie(Movie* m);
	/**
	 * this function gets a new professional and add it to the professional
	 * list
	 * @param p: the new professional to add
	 */
	int addNewProfessional(Professional* p);
	/*
	 * this function gets id and find the movie with this id,
	 * if it didnt find it return NULL
	 * @param id: the id of the movie
	 * @return: the movie or NULL if didnt find
	 */
	Movie* findMovieById(string id);
	/*
	 * this function gets id and find the pro with this id,
	 * if it didnt find it return NULL
	 * @param id: the id of the pro
	 * @return: the pro or NULL if didnt find
	 */
	Professional* findProById(string id);
	/**
	 * this function gets a movie id and professional id and add the
	 * professional with this id to the movie with movie id
	 * @param movieId: the id of the movie
	 * @param pId: the id of the professional
	 */
	int addProfessionalToMovie(string movieId, string pId);
	/**
	 * this function gets a movie id and a genre and add the genre to the
	 * genres list of the movie
	 * @param movieId: the id of the movie
	 * @param genre: the genre to add
	 */
	int addGenreToMovie(string movieId, string genre);
	/**
	 * this function gets a movie id and a sort type and set the sort
	 * type of the movie
	 * @param movieId: the id of the movie
	 * @param sortType: the sort type to set
	 */
	int setSortForMovie(string movieId, int sortType);
	/**
	 * this function gets a movie id and delete the movie from the movies
	 * list
	 * @param movieId: the id of the movie
	 */
	int deleteMovie(string movieId);
	/**
	 * this function gets a professional id and delete the professional
	 * from the professionals list
	 * @param pId: the id of the professional
	 */
	int deleteProfessional(string pId);
	/**
	 * this function gets a movie id and a professional id and delete
	 * the professional from the movie
	 * @param movieId: the id of the movie
	 * @param pId: the id of the professional
	 */
	int deleteProfessionalFromMovie(string movieId, string pId);
	/**
	 * this function print all the movies from the movies list using
	 * the single print function
	 */
	void printAllMovies();
	/**
	 * this function print all the professionals from the professionals list using
	 * the single print function
	 */
	void printAllProfessionals();
	/**
	 * this function print all the professionals of a given movie
	 * @param movieId: the id of the movie
	 */
	int printProfessionalsOfMovie(string movieId);
	/**
	 * this function print the information of a given movie
	 * @param movieId: the id of the movie
	 */
	void printMovie(string movieId);
	/**
	 * this function get the input for merge movies function
	 * @return: if the function succeed or failed
	 */
	int mergeInput();
	/**
	 * this function gets an array of ids and the length of the array
	 * and merge all the movies with the ids in the array using the
	 * + operator
	 * @param ids: the array of ids
	 * @param length: the length of the array
	 * @return: a new movie that merged from all of the movies in the array
	 */
	Movie* mergeMovies(list<string> ids);
	/**
	 * this function gets a professional id and print all the movies with this
	 * professional
	 * @param pId: the id of the professional
	 */
	int printMoviesWithProfessional(string pId);
	/**
	 * this function gets a genre and print all the movies with this genre
	 * @param genre: the genre
	 */
	void printMoviesWithGenre(string genre);
};

#endif
