#if!defined(MOVIE_H)
#define MOVIE_H

#include <string>

using namespace std;

class movie {
public:
	//***
    //Pre: none
    //post: creates a movie object
    //contains movie parameters
    //**
    movie(int=0, string="", string="", double=0, double =0, double = 0, double = -1);
    //***
    //Pre: movie object must exist
    //post: retreives the value
    //gets the value of the movie object
    //**
	double getMeta() const;
	double getUserReview() const;
	double getRottenT() const;
	double getVideoHound() const;
	int getID() const;
	string getTitle() const;
	string getYear() const;
    //***
    //Pre: movie object must exist
    //Post: sets an updated value in the movie object
    //updates the movie object
    //**
	void setMeta(double);
	void setUserReview(double);
	void setRottenT(double);
	void setVideoHound(double);
	void setID(int);
	void setTitle(string);
	void setYear(string);
private:
	int film;
	string title;
	string date;
	double metaCritic;
	double rottenTomatoes;
	double VH;
	double userReview;
};

#endif
