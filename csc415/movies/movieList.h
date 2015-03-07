#if!defined(MOVIELIST_H)
#define MOVIELIST_H

#include <string>
#include "movie.h"


using namespace std;

//varaibles for movies array
const int size = 2000;

class movieList {
public:
    //***
    //Pre: must be fed a .csv file of movies must have a preexisting array
    //Post: puts values in a movies array
    //creates a movies database
    //**
	void inputFmFile();
    //***
    //Pre: must be fed a populated array of movies
    //Post: calculates a user's proximity to a certain critic and gives recomendations
    //gets recomendations and calculates the proximity to a critic
    //**
	void calculate();
    //***
    //Pre: must be a populates movies array
    //Post: navigates the user to different functions in the program
    //allows the user to access functionality
    //**
    void directions();
    //
    //Pre: none
    //Post: adds a movie to the list
    //allows the user to add a movie to the list of movies
    //
    void addMovie();
    //
    //Pre: must have existing space in the list
    //Post: updates information about a movie
    //allows the user to update information in the list
    //
    void update();
    //
    //Pre: has data in the list
    //Post: returns movie recomendations
    //calls calculate and is used to get recomendations for moives
    //
    void get();
    //
    //Pre: populated list of movies
    //post: outputs data stream
    //used to print out the entire list of movies to a file
    //
    void print();
private:
    int totalMovies;
    int count;
	movie listMovies[size];
    string userRequest;
    string userInput;
};

#endif
