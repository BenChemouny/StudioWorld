/*
 * student name: Nadav Schweitzer
 * exercise name: ex3
 * file description: cinema class
 */
#include "Cinema.h"
#include "Actor.h"
#include "Director.h"
#include "ScreenWriter.h"
#include "Producer.h"
#include <list>
#include <string>
#include <string.h>
using namespace std;
/**
 * empty constructor of cinema class
 */
Cinema::Cinema()
{
}
/*
 * this function start the program itself and wait for the user to type data
 */
void Cinema::start()
{
	Movie* newMovie;
	Professional* newPro;
	string movieId;
	string genre;
	string pId;
	int sortType;
	int success;
	int printmsg;
	int command;
	//continue to run until the user type -1
	do
	{
		success = 1;
		printmsg = 1;
		cin>>command;
		//get a command and do what it says
		switch(command)
		{
		case -1:
			printmsg = 0;
			break;
		case 1:
			newMovie = scanMovie();
			success = addNewMovie(newMovie);
			break;
		case 2:
			newPro = scanProfessional();
			if(newPro != NULL)
			{
				success = addNewProfessional(newPro);
			}
			else
			{
				success = 0;
			}
			break;
		case 3:
			cin>>movieId;
			cin>>pId;
			success = addProfessionalToMovie(movieId, pId);
			break;
		case 4:
			cin>>movieId;
			cin>>genre;
			success = addGenreToMovie(movieId, genre);
			break;
		case 5:
			cin>>movieId;
			cin>>sortType;
			success = setSortForMovie(movieId, sortType);
			break;
		case 6:
			cin>>movieId;
			success = printProfessionalsOfMovie(movieId);
			if(success)
				printmsg = 0;
			break;
		case 7:
			cin>>movieId;
			printMovie(movieId);
			printmsg = 0;
			break;
		case 8:
			success = mergeInput();
			break;
		case 9:
			cin>>pId;
			success = printMoviesWithProfessional(pId);
			if(success)
				printmsg = 0;
			break;
		case 10:
			cin>>movieId;
			success = deleteMovie(movieId);
			break;
		case 11:
			cin>>pId;
			success = deleteProfessional(pId);
			break;
		case 12:
			cin>>movieId;
			cin>>pId;
			success = deleteProfessionalFromMovie(movieId, pId);
			break;
		case 13:
			printAllMovies();
			printmsg = 0;
			break;
		case 14:
			printAllProfessionals();
			printmsg = 0;
			break;
		case 15:
			cin>>genre;
			printMoviesWithGenre(genre);
			printmsg = 0;
			break;
		default:
			success = 0;
			break;
		}
		if(printmsg)
		{
			//print if the command succeed or failed
			if(success)
			{
				cout<<"Success"<<endl;
			}
			else
			{
				cout<<"Failure"<<endl;
			}
		}
	}while(command != -1);
}
/*
 * this function scan for an input until the \n char
 * @return: the input as a string
 */
string Cinema::scanInput()
{
	char input;
	string scanned = "";
	cin.get();
	//continue to scan until we reach \n
	do
	{
		input = cin.get();
		if(input != '\n')
			scanned += input;
	}while(input != '\n');
	//return the string
	return scanned;
}
/**
 * this function scan a movie from the screen and return it
 * @return: the new movie that we scanned
 */
Movie* Cinema::scanMovie()
{
	int length, publishYear;
	string id, name, summary;
	float rate;
	Movie* newMovie;

	cin>>id;
	cin>>name;
	cin>>length;
	cin>>publishYear;
	cin>>rate;
	summary = scanInput();
	//if there was an error new movie return NULL
	newMovie = new Movie(id,name,length,publishYear, rate, summary);
	newMovie->setSortType(ById);
	return newMovie;
}
/**
 * this function scan a professional from the screen and return it
 * @return: the new professional that we scanned
 */
Professional* Cinema::scanProfessional()
{
	int type, age;
	string info, name, sgender, id;
	enum Gender gender;

	cin>>type;
	cin>>id;
	cin>>age;
	cin>>info;
	cin>>sgender;
	name = scanInput();

	if(!strcmp(sgender.c_str(), "male"))
	{
		gender = Male;
	}
	else if(!strcmp(sgender.c_str(), "female"))
	{
		gender = Female;
	}

	Professional* newPro;
	switch(type)
	{
	case 0:
		newPro = new Director(id, name, info, age, gender);
		break;
	case 1:
		newPro = new Actor(id, name, info, age, gender);
		break;
	case 2:
		newPro = new ScreenWriter(id, name, info, age, gender);
		break;
	case 3:
		newPro = new Producer(id, name, info, age, gender);
		break;
	default:
		newPro = NULL;
		break;
	}
	//if there was an error newPro will be NULL
	return newPro;
}
/**
 * this function gets a new movie and add it to the movies list
 * @param m: the new movie to add
 */
int Cinema::addNewMovie(Movie* m)
{
	//if the movie is NULL or illegal the addition will fail
	if(m == NULL)
	{
		return 0;
	}
	if(m->getLength() < 0 || m->getPublishYear() < 0 || m->getRate() < 0.0f || m->getRate() > 10.0f)
	{
		delete m;
		return 0;
	}
	//check that the movie isnt exist
	list<Movie*>::iterator it;
	for(it = movies.begin(); it != movies.end(); it++)
	{
		if(!strcmp((*it)->getId().c_str(),m->getId().c_str()))
		{
			return 0;
		}
	}
	movies.push_back(m);
	//return succeed
	return 1;
}
/**
 * this function gets a new professional and add it to the professional
 * list
 * @param p: the new professional to add
 */
int Cinema::addNewProfessional(Professional* p)
{
	//check that the pro isnt exist
	list<Professional*>::iterator it;
	for(it = professionals.begin(); it != professionals.end(); it++)
	{
		if(!strcmp((*it)->getId().c_str(),p->getId().c_str()))
			return 0;
	}
	professionals.push_back(p);
	return 1;
}
/*
 * this function gets id and find the movie with this id,
 * if it didnt find it return NULL
 * @param id: the id of the movie
 * @return: the movie or NULL if didnt find
 */
Movie* Cinema::findMovieById(string id)
{
	list<Movie*>::iterator it;
	Movie* movie = NULL;
	for(it = movies.begin(); it != movies.end(); it++)
	{
		if(!strcmp((*it)->getId().c_str(), id.c_str()))
		{
			movie = (*it);
			break;
		}
	}
	return movie;
}
/*
 * this function gets id and find the pro with this id,
 * if it didnt find it return NULL
 * @param id: the id of the pro
 * @return: the pro or NULL if didnt find
 */
Professional* Cinema::findProById(string id)
{
	list<Professional*>::iterator it;
	Professional* pro = NULL;
	for(it = professionals.begin(); it != professionals.end(); it++)
	{
		if(!strcmp((*it)->getId().c_str(),id.c_str()))
		{
			pro = (*it);
			break;
		}
	}
	return pro;
}
/**
 * this function gets a movie id and professional id and add the
 * professional with this id to the movie with movie id
 * @param movieId: the id of the movie
 * @param pId: the id of the professional
 */
int Cinema::addProfessionalToMovie(string movieId, string pId)
{
	Movie* movie = findMovieById(movieId);
	if(movie == NULL)
		return 0;
	Professional* pro = findProById(pId);
	if(pro == NULL)
		return 0;
	if(!movie->addProfessional(pro))
		return 0;
	pro->IncAmountOfMovies();
	return 1;
}
/**
 * this function gets a movie id and a genre and add the genre to the
 * genres list of the movie
 * @param movieId: the id of the movie
 * @param genre: the genre to add
 */
int Cinema::addGenreToMovie(string movieId, string genre)
{
	Movie* movie = findMovieById(movieId);
	if(movie == NULL)
		return 0;
	movie->addGenre(genre);
	return 1;
}
/**
 * this function gets a movie id and a sort type and set the sort
 * type of the movie
 * @param movieId: the id of the movie
 * @param sortType: the sort type to set
 */
int Cinema::setSortForMovie(string movieId, int sortType)
{
	Movie* movie = findMovieById(movieId);
	if(movie == NULL)
		return 0;
	switch(sortType)
	{
	case 1:
		movie->setSortType(ById);
		break;
	case 2:
		movie->setSortType(ByAge);
		break;
	case 3:
		movie->setSortType(ByAmountOfMovies);
		break;
	default:
		return 0;
		break;
	}
	return 1;
}
/**
 * this function gets a movie id and delete the movie from the movies
 * list
 * @param movieId: the id of the movie
 */
int Cinema::deleteMovie(string movieId)
{
	list<Movie*>::iterator it;
	Movie* m = NULL;
	//find the movie
	for(it = movies.begin(); it != movies.end(); it++)
	{
		if(!strcmp((*it)->getId().c_str(),movieId.c_str()))
		{
			m = (*it);
			break;
		}
	}
	//if we didnt find we return NULL
	if(m == NULL)
		return 0;
	movies.remove(m);
	//release memory
	delete m;
	return 1;
}
/**
 * this function gets a professional id and delete the professional
 * from the professionals list
 * @param pId: the id of the professional
 */
int Cinema::deleteProfessional(string pId)
{
	Professional* pro = findProById(pId);
	if(pro == NULL)
		return 0;
	list<Movie*>::iterator movieIt;
	//delete the professional from all of the movies
	for(movieIt = movies.begin(); movieIt != movies.end(); movieIt++)
	{
		Movie* current = (*movieIt);
		if(current->hasProfessional(pId))
		{
			current->deleteProfessional(pro);
		}
	}
	professionals.remove(pro);
	//release memory
	delete pro;
	return 1;
}
/**
 * this function gets a movie id and a professional id and delete
 * the professional from the movie
 * @param movieId: the id of the movie
 * @param pId: the id of the professional
 */
int Cinema::deleteProfessionalFromMovie(string movieId, string pId)
{
	//check that the movie and pro exist
	Movie* movie = findMovieById(movieId);
	if(movie == NULL)
		return 0;
	Professional* pro = findProById(pId);
	if(pro == NULL)
		return 0;
	movie->deleteProfessional(pro);
	pro->DecAmountOfMovies();
	return 1;
}
/**
 * this function print all the movies from the movies list using
 * the single print function
 */
void Cinema::printAllMovies()
{
	list<Movie*>::iterator it;
	for(it = movies.begin(); it != movies.end(); it++)
	{
		(*it)->print();
	}
}
/**
 * this function print all the professionals from the professionals list using
 * the single print function
 */
void Cinema::printAllProfessionals()
{
	list<Professional*>::iterator it;
	for(it = professionals.begin(); it != professionals.end(); it++)
	{
		(*it)->print();
	}
}
/**
 * this function print all the professionals of a given movie
 * @param movieId: the id of the movie
 */
int Cinema::printProfessionalsOfMovie(string movieId)
{
	Movie* movie = findMovieById(movieId);
	if(movie == NULL)
		return 0;
	movie->printProfessionals();
	return 1;
}
/**
 * this function print the information of a given movie
 * @param movieId: the id of the movie
 */
void Cinema::printMovie(string movieId)
{
	Movie* movie = findMovieById(movieId);
	movie->print();
}
/**
 * this function get the input for merge movies function
 * @return: if the function succeed or failed
 */
int Cinema::mergeInput()
{
	char input;
	string value = "";
	list<string> ids;
	Movie* newMovie;
	cin.get();
	do
	{
		input = cin.get();
		if(input != '\n')
		{
			if(input == ',')
			{
				ids.push_back(value);
				value = "";
			}
			else
			{
				value += input;
			}
		}
		else
		{
			ids.push_back(value);
		}
	}while(input != '\n');
	newMovie = mergeMovies(ids);
	return addNewMovie(newMovie);
}
/**
 * this function gets an array of ids and the length of the array
 * and merge all the movies with the ids in the array using the
 * + operator
 * @param ids: the array of ids
 * @param length: the length of the array
 * @return: a new movie that merged from all of the movies in the array
 */
Movie* Cinema::mergeMovies(list<string> ids)
{
	list<string>::iterator it;
	it = ids.begin();
	Movie* nextMovie;
	Movie* currentMovie = findMovieById(*it);
	if(currentMovie == NULL)
		return NULL;
	it++;
	for(; it != ids.end(); it++)
	{
		 nextMovie = findMovieById(*it);
		 if(nextMovie == NULL)
			 return NULL;
		 currentMovie = *currentMovie + *nextMovie;
	}
	return currentMovie;
}
/**
 * this function gets a professional id and print all the movies with this
 * professional
 * @param pId: the id of the professional
 */
int Cinema::printMoviesWithProfessional(string pId)
{
	if(findProById(pId) == NULL)
		return 0;
	list<Movie*>::iterator moviesIt;
	for(moviesIt = movies.begin(); moviesIt != movies.end(); moviesIt++)
	{
		if((*moviesIt)->hasProfessional(pId))
		{
			(*moviesIt)->print();
		}
	}
	return 1;
}
/**
 * this function gets a genre and print all the movies with this genre
 * @param genre: the genre
 */
void Cinema::printMoviesWithGenre(string genre)
{
	list<Movie*>::iterator movieIt;
	list<string>::iterator genreIt;
	Movie* currentMovie = NULL;
	for(movieIt = movies.begin(); movieIt != movies.end(); movieIt++)
	{
		currentMovie = (*movieIt);
		list<string> currentGenres = currentMovie->getGenres();
		for(genreIt = currentGenres.begin(); genreIt != currentGenres.end(); genreIt++)
		{
			if(!strcmp((*genreIt).c_str(), genre.c_str()))
			{
				currentMovie->print();
				break;
			}
		}
	}
}