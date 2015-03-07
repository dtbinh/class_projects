#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "movie.h"
#include "movieList.h"

using namespace std;

int main(void) {
    
	movieList jakeMovies;
    
    jakeMovies.inputFmFile();
    
    jakeMovies.directions();
    
	return 0;
}
