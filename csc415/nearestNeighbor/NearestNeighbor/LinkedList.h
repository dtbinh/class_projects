//LinkedList.h

#include <iostream>
#include "Location.h"

using namespace std;

struct LinkedNode 
{
	Location storedLocation;
	LinkedNode *nextPtr;
};

class LinkedList
{
	private:
		LinkedNode *head;
		int size;
	
	public:
		LinkedList();
		~LinkedList();
		LinkedList(const LinkedList&);
	
		void addLocation(Location);
		Location getLocationAtIndex(int);
		int getListSize();
	
		friend ostream& operator<<(ostream&, LinkedList&);
};
