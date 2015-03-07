// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <string>

#include "movie.h"
#include "movieList.h"

using namespace std;

//outline fot movie object
movie::movie(int filmID, string filmTitle, string year, double meta,
				double rottenT, double videoHound, double UR) {
	film = filmID;
	title = filmTitle;
	date = year;
	metaCritic = meta;
	rottenTomatoes = rottenT;
	VH = videoHound;
	userReview = UR;
}

//getters for movies list
double movie::getMeta() const {
	return metaCritic;
}
double movie::getUserReview() const {
	return userReview;
}
double movie::getRottenT() const {
	return rottenTomatoes;
}
double movie::getVideoHound() const {
	return VH;
}
int movie::getID() const {
	return film;
}
string movie::getTitle() const {
	return title;
}
string movie::getYear() const {
	return date;
}

//setters for movie list
void movie::setMeta(double meta) {
	metaCritic = meta;
}
void movie::setUserReview(double usrR) {
	userReview = usrR;
}
void movie::setRottenT(double rottenT) {
	rottenTomatoes = rottenT;
}
void movie::setVideoHound(double videoHound) {
	VH = videoHound;
}
void movie::setID(int ID) {
	film = ID;
}
void movie::setTitle(string name) {
	title = name;
}
void movie::setYear(string year) {
	date = year;
}
