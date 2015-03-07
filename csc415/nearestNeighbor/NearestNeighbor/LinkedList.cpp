#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() 
{
	head = NULL;
	size = 0;
}

LinkedList::~LinkedList()
{
	LinkedNode *current = head;
	
	while( current != NULL ) 
	{
		LinkedNode *next = current->nextPtr;
		delete current;
		current = next;
	}
	
	head = NULL;
}

LinkedList::LinkedList(const LinkedList &rhs)
{
	size = rhs.size;
	
	LinkedNode* cur = rhs.head;
	LinkedNode* end = NULL;

    head = NULL;
    
	while (cur)
	{
		LinkedNode* n = new LinkedNode;
		n->storedLocation = cur->storedLocation;
		
		if (!head) 
		{
			head = n;	
			end = head;
		} 
		else 
		{
			end->nextPtr = n;
			end = n;
		}

		cur = cur->nextPtr;
	}
}
	
void LinkedList::addLocation(Location newLocation)
{
	//Create a new node
	LinkedNode *newNode = new LinkedNode;
	newNode->storedLocation = newLocation;
	newNode->nextPtr = NULL;
	
	if (size == 0)
		head = newNode;
	else
	{
		LinkedNode *ptr;	
		ptr = head;
		
		//Traverse the linked list until the current last node is reached
		while (ptr->nextPtr != NULL)
		{
			ptr = ptr->nextPtr;
		}
	
		//Add the new node as the new last node of the list
		ptr->nextPtr = newNode;
	}
	
	//Increment the size of the list
	size++;
}

Location LinkedList::getLocationAtIndex(int targetIndex)
{
	int currentIndex = 0;	
	LinkedNode *currentNode = head;

	if (currentIndex >= size || currentIndex < 0)
	{
		cout << "Error: Invalid index value, returning a blank Location object" << endl;
		Location blank;
		return blank;
	}
	else
	{
		//Traverse the linked list
		while (currentIndex < targetIndex)
		{
			currentNode = currentNode->nextPtr;
			currentIndex++;
		}
		
		return (currentNode->storedLocation);
	}
}

int LinkedList::getListSize()
{
	return size;
}

ostream& operator << (ostream& outStr, LinkedList& rhs)
{
	LinkedNode *tmpPtr = rhs.head;
	outStr << endl;
	if (rhs.size == 0)
		outStr << "Sorry, the list is empty. Add some elements and then try again." << endl;
	else
		while (tmpPtr != NULL) 
		{
			outStr << tmpPtr->storedLocation << " " << endl;
			tmpPtr = tmpPtr->nextPtr;
		}
	return outStr;
}