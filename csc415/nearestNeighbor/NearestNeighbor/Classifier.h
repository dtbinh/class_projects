//Classifier.h

#include "Location.h"
#include "LinkedList.h"

class Classifier
{
	private:
	
		//This pointer stores the array of rated Locations that the input Location can be compared to
		Location *ratedLocationArray;
		
		//The number of rated locations in that array
		int numRatedLocations;
		
		//-----------------------------------------------------------------------------------------
		//
		//  Function: getListOfLocations(Location&);
		//
		//    Parameters: 	Location - the location without an ASR rating
		//    
		//    Pre-condition: The Chemical arrays of the rated and input Locations are in alphabetical order based on Chemical names
		// 	  Post-condition: Returns a linked list populated with Locations that have Chemicals in common with the input location
		//-----------------------------------------------------------------------------------------
		LinkedList getListOfLocations(Location&);
		
		//The ranges of the values for each of the pollution values for the Chemicals
		double rangeFugitive, rangeStack, rangeWater, rangeTotal, rangeProduction;
		
	public:
		Classifier(Location*, int, double, double, double, double, double, double, double, double, double, double);
		
		//-----------------------------------------------------------------------------------------
				//
				//  Function: getListOfLocations(Location&);
				//
				//    Parameters: 	Location - the location without an ASR rating
				//    
				//    Pre-condition: The Chemical arrays of the rated and input Locations are in alphabetical order based on Chemical names and the getListOfLocations method has been called to narrow down the search for a nearest rated Location
				// 	  Post-condition: Returns the ASR rating of the input Location using classification and sets the ASR rating of the input Location
				//-----------------------------------------------------------------------------------------
		int getRatingOfLocation(Location&);
};