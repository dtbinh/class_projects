//SystemManager.h

#include <iostream>
#include "Classifier.h"

using namespace std;

class SystemManager
{
private:
    Classifier *classifier;
    Chemical allChemicals[200];
    Location allLocations[500];
    
public:
    SystemManager();
    ~SystemManager();
    SystemManager(const SystemManager&);
    void processInput(string);
    void printAllChemicals(Chemical[], int);
    void printAllLocations(Location[], int);
};