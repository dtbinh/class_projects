//Classifier.cpp

#include <iostream>
#include <string>
#include <cmath>
#include "Classifier.h"

using namespace std;

Classifier::Classifier(Location* ratedArray, int numRated, double maxFugitive, double minFugitive, double maxStack, double minStack, double maxWater, double minWater, double maxTotal, double minTotal, double maxProduction, double minProduction)
{
	rangeFugitive = maxFugitive - minFugitive;
	rangeStack = maxStack - minStack;
	rangeWater = maxWater - minWater;
	rangeTotal = maxTotal - minTotal;
	rangeProduction = maxProduction - minProduction;
	ratedLocationArray = ratedArray;
	numRatedLocations = numRated;
}

int Classifier::getRatingOfLocation(Location &inLocation)
{
	//The narrowed-down linked list of possible nearest Locations to the input Location
	LinkedList nearbyLocations = getListOfLocations(inLocation);
	
	//The indices used to access the chemicals in the input Location's chemical array and the current rated Location's chemical 
	int inpChemInd = 0, ratedChemInd = 0;
	
	//The number of chemicals in the rated Location's chemical array
	int numRatedChems;
	//The number of chemicals in the input Location's chemical array
	int numOfCommonChems;
	
	//The returned value of the compare method when the names of two chemicals are compared
	int chemComparisonRes; 
	
	//The number of chemicals in the input Location's chemical array
	int numInputChems = inLocation.getNumChemicals();
	
	//The array of chemicals in the input Location
	Chemical *inpChemicalList = inLocation.getChemicalList();
	
	//The array of chemicals in the rated Location
	Chemical *ratedChemicalList;
	
	//The rated Location that is currently being compared to the input in the loop
	Location currentRatedLocation;
	
	//The smallest distance calculated after all rated Locations have been considered
	double currentBest = 0;
	
	//The index of the rated Location with the smallest distance to the input Location 
	int bestInd;
	
	//This is set to true if no distances have been calculated yet
	bool first = true;
	
	//tempSum is the sum that is added to within the radical for the euclidDistane. EuclidDistance is used for calculating the rating.
	double tempSum, euclidDistance;
	
	//Creating an int for this size so that the getListSize method is not called continuously
	int nearbyLocationsSize = nearbyLocations.getListSize();
	
	//Walk through each element of the nearbyLocations list
	for(int rLocInd = 0; rLocInd < nearbyLocationsSize; rLocInd++)
	{
		inpChemInd = 0;
		ratedChemInd = 0;
		
		tempSum = 0;
		euclidDistance = 0;
		
		currentRatedLocation = nearbyLocations.getLocationAtIndex(rLocInd);
		
		numRatedChems = currentRatedLocation.getNumChemicals();
		
		ratedChemicalList = currentRatedLocation.getChemicalList();
		
		
		while (inpChemInd < numInputChems && ratedChemInd < numRatedChems)
		{
			//Compare the names of Chemicals at the respective arrays' current index values
			chemComparisonRes = inpChemicalList[inpChemInd].getName().compare(ratedChemicalList[ratedChemInd].getName());
			
			if (chemComparisonRes < 0) //The Chemical of the input Location cannot exist in the ratedLocation 
			{
				tempSum += inpChemicalList[inpChemInd].calcSumSquare(rangeFugitive, rangeStack, rangeWater, rangeTotal, rangeProduction);
				
				//Increment only the input Chemical array index
				inpChemInd++;
			}
			else if (chemComparisonRes > 0) //The Chemical of the input Location can still exist in the ratedLocation. 
			{
				//Increment only the input Chemical array index
				ratedChemInd++;
				
				if(ratedChemInd == numRatedChems)
				{
					while(inpChemInd < numInputChems)
					{
						tempSum += inpChemicalList[inpChemInd].calcSumSquare(rangeFugitive, rangeStack, rangeWater, rangeTotal, rangeProduction);
						inpChemInd++;
					}
				}
			}
			else //Input Chemical exists in both the input Location and the rated Location
			{
				tempSum += inpChemicalList[inpChemInd].calcSumSquare(ratedChemicalList[ratedChemInd],rangeFugitive, rangeStack, rangeWater, rangeTotal, rangeProduction);
				//Increment both indices
				inpChemInd++;
				ratedChemInd++;
			}
		}
		
		euclidDistance = sqrt(tempSum);
		
		// Logic to determine if this is the smallest distance so far.
		if (first)
		{
			currentBest = euclidDistance;
			bestInd = rLocInd;
			first = false;
		}
		else if(euclidDistance < currentBest) // first boolean 
		{
			euclidDistance = currentBest;
			bestInd = rLocInd;
		}	
	}
	
	Location bestLocation = nearbyLocations.getLocationAtIndex(bestInd);
	
	cout << "The closest rated location to the input location is: \n" << bestLocation << endl;
	
	cout << "The Chemicals in the closest rated location are: \n\n" << bestLocation.listAllChemicals() << endl;
	
	inLocation.setRating(bestLocation.getRating());
	return inLocation.getRating();
}

LinkedList Classifier::getListOfLocations(Location &inLocation)
{
	//A pointer to the LinkedList to be returned
	LinkedList *resultList = new LinkedList;
	
	//Many of these values are the same as those used in the getRatingOfLocation method
	int numInputChems = inLocation.getNumChemicals();
	int inpChemInd = 0, ratedChemInd = 0;
	int numRatedChems;
	int chemComparisonRes;
	int numOfCommonChems;
	int greatestNumOfCommonChems = 0;
	Location currentRatedLocation;
	Chemical *inpChemicalList = inLocation.getChemicalList();
	Chemical *ratedChemicalList;
	
	//Iterate through each rated location
	for (int ratedLocationInd = 0; ratedLocationInd < numRatedLocations-1; ratedLocationInd++)
	{
		numOfCommonChems = 0;
		inpChemInd = 0;
		ratedChemInd = 0;
		
		currentRatedLocation = ratedLocationArray[ratedLocationInd];
		numRatedChems = currentRatedLocation.getNumChemicals();
		ratedChemicalList = currentRatedLocation.getChemicalList();
		
		//This logic is recycled from the getRatingOfLocation method
		while (inpChemInd < numInputChems && ratedChemInd < numRatedChems)
		{
			
			chemComparisonRes = inpChemicalList[inpChemInd].getName().compare(ratedChemicalList[ratedChemInd].getName());
			
			if (chemComparisonRes < 0)
				inpChemInd++;
			else if (chemComparisonRes > 0)
			{
				ratedChemInd++;
			}
			else
			{
				numOfCommonChems++;
				inpChemInd++;
				ratedChemInd++;
			}
		}
		
		//Logic to figure out what is the greatest number of chemicals in common among the input Location and rated Locations
		if (numOfCommonChems == greatestNumOfCommonChems)
			resultList->addLocation(currentRatedLocation);
		else if (numOfCommonChems > greatestNumOfCommonChems)
		{
			//If the former greatest number of common chemicals is smaller than the current number of common chems, the greatest number of common chemicals 
			greatestNumOfCommonChems = numOfCommonChems;
			
			//Delete the contents of the list of Locations with too few chemicals in common and create a new LinkedList with 
			delete resultList;	
			resultList = new LinkedList;
			resultList->addLocation(currentRatedLocation);
		}
		
	}
	
	
	return *resultList;
}