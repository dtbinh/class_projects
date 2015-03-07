//SystemManager.cpp

#include "SystemManager.h"
#include <fstream>
#include <cstring>
#include <climits>

using namespace std;

SystemManager::SystemManager(){
      
	//*************************************************************************
	//
	// Creating a local database (in arrau form) of all locations that contain
	// information on how much chemicals they contain.
	//
	//*************************************************************************
    
	ifstream location_infile;
	int location_counter;
	int rating=0;
    
	location_infile.open("bf_chemnames.txt");
	location_counter = 0;
    
	location_infile.ignore(200, '\n');
	//ignore the first line of the file
    
	string state, address, facility, city, chem_name, temp_fac_name="";
	double FA, SA, W, TR, PW, maxFA=0, maxSA=0, maxW=0, maxTR=0, maxPW=0, minFA=INT_MAX, minSA=INT_MAX, minW=INT_MAX, minTR=INT_MAX, minPW=INT_MAX;
    
	for (int i=0; i < 1460; i++) {
        
		char charArray[300];
		string splitLine[5];
		int location_chem_counter=0;
        
        //**************INDEX**************
	    // splitLine[0] - facility name
	    // splitLine[1] - street address
	    // splitLine[2] - city
	    // splitLine[3] - state
	    // splitLine[4] - chemical name
	    //*********************************
        for (int j=0; j<5;j++){
            location_infile.getline(charArray,300,'\t');
            splitLine[j] = charArray;
	    }

	    facility = splitLine[0];
	    address = splitLine[1];
	    city = splitLine[2];
	    state = splitLine[3];
	    chem_name = splitLine[4];
	    location_infile >> FA;
	    location_infile >> SA;
	    location_infile >> W;
	    location_infile >> TR;
	    location_infile >> PW;
        if(FA > maxFA)
            maxFA = FA;
        if(SA > maxSA)
            maxSA = SA;
        if(W > maxW)
            maxW = W;
        if(TR > maxTR)
            maxTR = TR;
        if(PW > maxPW)
            maxPW = PW;
        if(FA != 0 && FA < minFA)
            minFA = FA;
        if(SA != 0 && SA < minSA)
            minSA = SA;
        if(W != 0 && W < minW)
            minW = W;
        if(TR != 0 && TR < minTR)
            minTR = TR;
        if(PW != 0 && PW < minPW)
            minPW = PW;

        rating = (int)((TR - 11159) / 11159);

	    Chemical newChemical(chem_name, FA, SA, W, TR, PW);

	    //cout << newChemical.listIntData();
        
	    //Only make a new location object if the faculty is different
	    if (splitLine[0] != temp_fac_name){
	    	temp_fac_name = splitLine[0];
	    	location_chem_counter=0;
	    	allLocations[location_counter] = Location(address, state, facility, city);
	    	allLocations[location_counter].addChemical(newChemical);
	    	location_chem_counter++;
	    	location_counter++;
	    }
	    else{
	    	//The -1 fixes increment of the location counter in previous if
	    	allLocations[location_counter-1].addChemical(newChemical);
	    	location_chem_counter++;
	    }
	}

	for (int i=0; i < location_counter; i++){
		allLocations[i].calcRating();
	}
    
    
	//*************************************************************************
    
    
    
	//*************************************************************************
	//
	// Creating a local database (in array form) of all chemical information
	// that is available. It is stored as allChemicals[].
	//
	//*************************************************************************
	ifstream chem_infile;
	int chem_counter;
    
	chem_infile.open("chemicals.txt");
	chem_counter = 0;
    
	chem_infile.ignore(200, '\n');
	//ignore the first line of the file
    
	string name, ID;
	bool cleanAirAct, pbt, metal, carcinogen;
    
	for (int i=0; i < 164; i++) {
        
		char charArray[300];
		string splitLine[6];
        
        for (int j=0; j<6;j++){
        	if (j!=5){
                chem_infile.getline(charArray,200,'\t');
                splitLine[j] = charArray;
            }
            else{
                chem_infile.getline(charArray,200, '\n');
                splitLine[j] = charArray;
            }
	    }
        
	    //**************INDEX**************
	    // splitLine[0] - chemical name
	    // splitLine[1] - CAS No. / ID
	    // splitLine[2] - Clean Air Act?
	    // splitLine[3] - Metal?
	    // splitLine[4] - Carcinogen?
	    // splitLine[5] - PBT?
	    //*********************************
        
        //CLEANING THE DATA
        for(int j=1;j<6;j++)
            for(int k=0;k<splitLine[j].length();k++)
                if(splitLine[j][k]==' ')
                    splitLine[j].erase(k,1);
        
        name = splitLine[0];
        ID = splitLine[1];
        
        if (splitLine[2] == "YES")
        	cleanAirAct = true;
        else
        	cleanAirAct = false;
        
        if (splitLine[3] == "YES")
        	metal = true;
        else
        	metal = false;
        
        if (splitLine[4] == "YES")
        	carcinogen = true;
        else
        	carcinogen = false;
        
        if (splitLine[5] == "PBT")
        	pbt = true;
        else
        	pbt = false;
        
        allChemicals[i] = Chemical(name, ID, cleanAirAct, metal, carcinogen, pbt);
        chem_counter++;
	}
    cout << endl << endl;
//    printAllChemicals(allChemicals,chem_counter);
//    printAllLocations(allLocations,location_counter);
    classifier = new Classifier(allLocations,location_counter,maxFA,minFA,maxSA,minSA,maxW,minW,maxTR,minTR,maxPW,minPW);

	Location inpLocation("421 Brownfield Road", "NJ", "Area 51", "Ewing");
	Chemical c1("ANTIMONY COMPOUNDS", 0, 0, 0, 2181, 2181);
	Chemical c2("BARIUM COMPOUNDS", 0, 0, 0, 429, 429);
	Chemical c3("ETHYLBENZENE", 31, 303, 0, 334, 12787);
	Chemical c4("N-BUTYL ALCOHOL", 68, 595, 0, 663, 28217);
	Chemical c5("TOLUENE", 48, 145, 0, 193, 3183);
	Chemical c6("XYLENE (MIXED ISOMERS)", 55, 541, 0, 596, 22515);
	
	inpLocation.addChemical(c1);
	inpLocation.addChemical(c2);
	inpLocation.addChemical(c3);
	inpLocation.addChemical(c4);
	inpLocation.addChemical(c5);
	inpLocation.addChemical(c6);
	
	classifier->getRatingOfLocation(inpLocation);
	
	cout << "The rating for the location: \n" << inpLocation << endl;

	//*************************************************************************
}

SystemManager::SystemManager(const SystemManager& rhs){}

SystemManager::~SystemManager(){
    delete classifier;
}

void SystemManager::printAllChemicals(Chemical chemArr[],int maxSize)
{
    cout << endl << endl << "PRINTING ALL CHEMICALS..." << endl;
    for(int i=0;i<maxSize;i++)
        cout << chemArr[i];
}
void SystemManager::printAllLocations(Location locationArr[],int maxSize)
{
    cout << endl << endl << "PRINTING ALL LOCATIONS..." << endl;
    for(int i=0;i<maxSize;i++)
        cout << locationArr[i];
}