#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

#include "movieList.h"
#include "movie.h"

using namespace std;

void movieList::inputFmFile() {
	//initilizes variables
	string inputFile;
	totalMovies = 0;

	//gets users requested file
	cout << "Enter the name of the file you wish to import: " << endl;
	cin >> inputFile;

	//creates the file stream for the file
	fstream inFile;

	inFile.open(inputFile.c_str());

	//haha I got to put string cheese in a real program
	string cheese;

	//skips the first three lines
	getline(inFile, cheese, '\r');
	getline(inFile, cheese, '\r');
	getline(inFile, cheese, '\r');

	//while not end of file
	while (!inFile.eof()) {
		//inFile >> lineHold;
		string one;
		string two;
		string three;
		string four;
		string five;
		string six;

		//delimits for comma
		for (int j = 0; j < 6; j++) {
			getline(inFile, one, ',');
			getline(inFile, two, ',');
			getline(inFile, three, ',');
			getline(inFile, four, ',');
			getline(inFile, five, ',');
			getline(inFile, six, '\r');
			movie next(atoi(one.c_str()), two, three, atof(four.c_str()),
				atof(five.c_str()), atof(six.c_str()));
			listMovies[totalMovies] = next;
		}

		totalMovies++;
	}
}
void movieList::directions() {
	//variables initilized
	userRequest = "";
	userInput = "";
	count = 0;

	//asks the user what they want to do
	cout
		<< "please enter what you would like to do: 'quit', add movies = 'add', update movie 'update', get recomendations 'get' or 'print' out the current data."
		<< endl;

	cin >> userRequest;

	//compares what the user wants us to do
	if (userRequest == "add") {
        addMovie();
	}
	if (userRequest == "update") {
        update();
    }
	if (userRequest == "get") {
        get();
	}
	if (userRequest == "print") {
        print();
    }
	//allows the user to exit the program
	if (userRequest == "quit") {
	  exit(0);
	}
	//catch for if user enters gibberish
	else
	  cout << "Your entry was invalid, please try again." << endl;
	directions();
}

void movieList::addMovie(){
    int numMovies = 0;
    
    cout << "how many movies would you like to add?";
    
    cin >> numMovies;
    
    //populates adds the requested amount of movies
    for (int i = 0; i < numMovies; i++) {
        //variables for population
        int film;
        string title;
        string date;
        double metaCritic;
        double rottenTomatoes;
        double VH;
        double UR;
        bool test;
        
        //gets the user's movie
        cout << "Please enter the film ID: " << endl;
        cin >> film;
        cout << "Please enter the film title: " << endl;
        cin >> title;
        cout << "Please enter the release date: " << endl;
        cin >> date;
        cout << "Please enter the MetaCritic score: " << endl;
        cin >> metaCritic;
        cout << "Please enter the Rotten Tomatoes score: " << endl;
        cin >> rottenTomatoes;
        cout << "Please enter the Video Hound score: " << endl;
        cin >> VH;
        cout << "Please enter your score: " << endl;
        cin >> UR;
        
        //creates a movie object
        movie uMov(film, title, date, metaCritic, rottenTomatoes, VH, UR);
        
        //checks if movie is already in the system
        for (int j = 0; j < totalMovies; j++) {
            if (uMov.getTitle() == listMovies[j].getTitle())
                test = true;
        }
        if (test == false)
            listMovies[totalMovies] = uMov;
        totalMovies++;
    }
    //goes to the user directive
    directions();
}

void movieList::update(){
    //initilizes varaibles
    int film;
    string title;
    string date;
    double metaCritic;
    double rottenTomatoes;
    double VH;
    double UR;
    bool test = false;
    
    //gets user's updated information
    cout
    << "please enter the title of the movie you would like to update"
    << endl;
    cin >> title;
    cout << "Please enter the release date: " << endl;
    cin >> date;
    cout << "Please enter the MetaCritic score: " << endl;
    cin >> metaCritic;
    cout << "Please enter the Rotten Tomatoes score: " << endl;
    cin >> rottenTomatoes;
    cout << "Please enter the Video Hound score: " << endl;
    cin >> VH;
    cout << "Please enter your score: " << endl;
    cin >> UR;
    cout << "Please enter the film ID: " << endl;
    cin >> film;
    
    //find the requested movie
    for (int i = 0; i < totalMovies; i++) {
        if (listMovies[i].getTitle() == title) {
            listMovies[i].setID(film);
            listMovies[i].setTitle(title);
            listMovies[i].setYear(date);
            listMovies[i].setMeta(metaCritic);
            listMovies[i].setRottenT(rottenTomatoes);
            listMovies[i].setVideoHound(VH);
            listMovies[i].setUserReview(UR);
            test = true;
        }
    }
    //if the movie does not exist
    if (test == false)
        cout
        << "The movie you have entered does not exist in the system yet."
        << endl;
    //returns to user directive
    movieList::directions();

}

void movieList::get(){
    //requests that the user make recomendations
    cout
    << "please review at least five of the movies with a score of 1, 2, 3 or 4, type 'stop' to stop reviewing."
    << endl;
    
    //allows the user to stop when requested
    while (userInput != "stop") {
        //makes sure that the user has reviewed at least 5 movies
        if (userInput == "stop" && count > 4)
		    continue;
        else
		    cout
            << "You have not reviewed enough films, please rate a few more."
            << endl;
        //prints movie to review
        cout << listMovies[count].getTitle() << endl;
        //takes in review for movie
        cin >> userInput;
        int reviewIn;
        reviewIn = atoi(userInput.c_str());
        listMovies[count].setUserReview(reviewIn);
        
        count++;
    }
    
    //calculates the reviews and outputs recomendations
    calculate();
    //returns to user directive
    directions();
}

void movieList::print(){
    //creates an out stream
    ofstream outStr;
    string fileName;
    bool worked = false;
    //asks what file to save to
    cout
    << "Enter the name of the file you would like to output to: "
    << endl;
    cin >> fileName;
    outStr.open(fileName.c_str());
    //makes sure that the file opens correctly
    if (outStr.fail()) {
        cerr << "error writing the file." << endl;
        outStr.clear();
        worked = false;
    } else
        worked = true;
    
    //outputs main file
    if (worked == true) {
        outStr << setw(15) << "Film ID";
        outStr << setw(15) << "Film Title";
        outStr << setw(15) << "Year";
        outStr << setw(15) << "Meta Critic";
        outStr << setw(15) << "Rotten Tomatoes";
        outStr << setw(15) << "Video Houd";
        outStr << setw(15) << "User Review" << endl;
        for (int i = 0; i < size; i++) {
            outStr << setw(15) << listMovies[i].getID();
            outStr << setw(15) << listMovies[i].getTitle();
            outStr << setw(15) << listMovies[i].getYear();
            outStr << setw(15) << listMovies[i].getMeta();
            outStr << setw(15) << listMovies[i].getRottenT();
            outStr << setw(15) << listMovies[i].getVideoHound();
            outStr << setw(15) << listMovies[i].getUserReview() << endl;
            
        }
    }
    //returns to user directive
    directions();

}

//calculates the closest critic
void movieList::calculate() {
	int numReviews = 0;
	int holder = 0;
	double crit0 = 0;
	double crit1 = 0;
	double crit2 = 0;
	double compare = 0;
	string closest;

	//for every review that the user has rated
	for (int i = 0; i < totalMovies; i++) {
		if (listMovies[i].getUserReview() != -1) {
			crit0 += pow((listMovies[i].getMeta() - listMovies[i].getUserReview()), 2);
			crit1 += pow((listMovies[i].getRottenT() - listMovies[i].getUserReview()), 2);
			crit2 += pow((listMovies[i].getVideoHound() - listMovies[i].getUserReview()), 2);
		}
	}
	//finishes the calculation
	crit0 = sqrt(crit0);
	crit1 = sqrt(crit1);
	crit2 = sqrt(crit2);

	//finds the critic with the lowest number
	compare = crit0;
	closest = "MetaCritic";
	if (compare > crit1) {
		compare = crit1;
		closest = "RottenTomatoes";
	}
	if (compare > crit2) {
		compare = crit2;
		closest = "VideoHound";
	}

	//asks the user how many reviews they want
	cout
		<< "please enter the number of movie recomendations you would like to see."
		<< endl;
	cin >> numReviews;

	//if metacritic print the first j results
	if (closest == "MetaCritic") {
		for (int j = 0; j < totalMovies; j++) {
			if ((listMovies[j].getUserReview() == -1) && (listMovies[j].getMeta() >= 3)) {
				cout << listMovies[j].getTitle() << endl;
				holder++;
			}
			if (holder >= numReviews)
				break;
		}
	}

	//if rottentomatoes print the first j results
	if (closest == "RottenTomatoes") {
		for (int j = 0; j < totalMovies; j++) {
			if ((listMovies[j].getUserReview() == -1) && (listMovies[j].getRottenT() >= 3)) {
				cout << listMovies[j].getTitle() << endl;
				holder++;
			}
			if (holder >= numReviews)
				break;
		}
	}

	//if videohound print the first j results
	if (closest == "VideoHound") {
		for (int j = 0; j < totalMovies; j++) {
			if ((listMovies[j].getUserReview() == -1) && (listMovies[j].getVideoHound() >= 3)) {
				cout << listMovies[j].getTitle() << endl;
				holder++;
			}
			if (holder >= numReviews)
				break;
		}
	}

}
