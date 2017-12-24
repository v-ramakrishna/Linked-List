// Assignment #1
// Name: Vijay Ramakrishna
// ASU ID: 1202948485
// ASU Email Address: vkramakr@asu.edu
// Description: This header file contains the necessary code to be able
//              to use a Linked List in Assignment 1. The class files for
//              the Country structure and singly Linked List class are included,
//              as well as corresponding methods for the Linked List. These
//              include a constructor, destructor, a method to add countries
//              to the list, a method to remove countries, a method to edit the
//              medal counts for countries, as well as a way to print all the data
//              which the user has entered into the Linked List.
//

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings
#include <stdlib.h> //to use dynamic memory allocation

using namespace std;

//struct Country represents some country information
struct Country
{
    string name;
    int gold;
    int silver;
    int bronze;
    struct Country * next;
};

//class LinkedList will contains a linked list of countries
class LinkedList
{
    private:
        struct Country * head;

    public:
        LinkedList();
        ~LinkedList();
        bool addCountry(string countryName, int gold, int silver, int bronze);
        bool removeCountry(string countryName);
        bool changeMedalCount(string countryName, string medal, int count);
        void printList();
};

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
//Description: The destructor is used to remove the linked list and free memory allocated. It does this by calling
//             the removeCountry method for each of the countries in the linked list. It increments each time it does,
//             and at the end, tells the user how many countries were removed from the list.
LinkedList::~LinkedList()
{
    struct Country * removerPointer = NULL;
    struct Country * holderPointer = NULL;
    string nameHolder;
    int incrementer = 0;
    if (head != NULL)
    {
            removerPointer = head;
            holderPointer = head;
    }
    if (removerPointer != NULL)
    {
        while (removerPointer != NULL)
        {
                removerPointer = holderPointer->next;
                nameHolder = holderPointer->name;
                removeCountry(nameHolder);
                incrementer++;
                holderPointer = removerPointer;
        }
    }
    cout << "The number of deleted countries is: " << incrementer << endl;
}

//Add Country
//Description: The Add Country method adds a new country to the linked list, using
//             arguments specified by the user in the main program to populate the
//             structure's information. Before being added, countries are sorted
//             alphabetically, and added to the list in this order. If lacking sufficient memory,
//             this method will return false.
bool LinkedList::addCountry(string newName, int gold, int silver, int bronze)
 {

    struct Country * newCountry = new Country;
    if (newCountry == NULL)
    {
        return false;
    }
    newCountry->name = newName;
    newCountry->gold = gold;
    newCountry->bronze = bronze;
    newCountry->silver = silver;

    struct Country * currentOnList = NULL;
    string currentName;
    struct Country * savePosition = NULL;
    string previousName;

    if (head != NULL)
    {
        currentOnList = head;
        currentName = head->name;
        savePosition = head;
        previousName = head->name;
    }
    if (head == NULL)
    {
        head = newCountry;
        head->next = NULL;
        return true;
    }
    else if (head != NULL && head->next == NULL)
    {
        int shortComparator = currentName.compare(newName);
        if (shortComparator < 0 || shortComparator == 0)
        {
            currentOnList->next = newCountry;
            newCountry->next = NULL;
            return true;
        }
        else
        {
      	  head = newCountry;
    	  newCountry->next = currentOnList;
    	  currentOnList->next = NULL;
    	  return true;
         }
    }
    else if (head != NULL && head->next != NULL)
    {
        int firstComparator = currentName.compare(newName);

        if (firstComparator > 0)
    	{
    		newCountry->next = currentOnList;
    		head = newCountry;
    		return true;

    	}
    	else
        {
            currentOnList = currentOnList->next;
            currentName = currentOnList->name;
        }
    	while (currentOnList->next != NULL)
    	{
    		int firstComparator = currentName.compare(newName);

    		if (firstComparator > 0)
    		{
    			savePosition->next = newCountry;
    			newCountry->next = currentOnList;
    			return true;

    		}
    		if (firstComparator < 0)
    		{
    		    savePosition = currentOnList;
    			currentOnList = currentOnList->next;
    			currentName = currentOnList->name;
    		}
    	}
    	if (currentOnList->next == NULL)
        {
            int firstComparator = currentName.compare(newName);
            if (firstComparator > 0)
            {
                newCountry->next = currentOnList;
                savePosition->next = newCountry;
                return true;
            }
            else
            {
                currentOnList->next = newCountry;
                newCountry->next = NULL;
                return true;
            }
        }
    }
    return false;
 }

//Remove Country
//Description: The Remove Country method searches for a country specified
//             by the user in the main program. If a country matching the specified
//             name is found, the country will be removed from the linked list,
//             and the memory it was allocated will be freed. Will return false if the
//             country is not actually in the list.
bool LinkedList::removeCountry(string someName)
 {
    string findCountryName = someName;
    struct Country * currentOnList = NULL;
    struct Country * nextOnList = NULL;
    string saveHeadName;
    string extractNextName;

    if (head != NULL)
    {
        currentOnList = head;
        nextOnList = head->next;
        saveHeadName = head->name;
    }

    if (head != NULL && head->next != NULL)
    {
        extractNextName = nextOnList->name;
    }
    if (head == NULL)
    {
        return false;
    }
    if (head != NULL && head-> next == NULL)
    {
        if (saveHeadName == findCountryName)
        {
            free(head);
            head = NULL;
            return true;
        }
        else
        {
            return false;
        }
    }
    while(currentOnList->next != NULL)
    {
        if(saveHeadName == findCountryName)
        {
            free(head);
            head = nextOnList;
            return true;
        }
        else if (extractNextName == findCountryName)
        {
            currentOnList->next = nextOnList->next;
            free(nextOnList);
            return true;
        }
        else
        {
            currentOnList = nextOnList;
            if (currentOnList->next == NULL)
            {
                return false;
            }
            nextOnList = currentOnList->next;
            extractNextName = nextOnList->name;
        }
    }
    return false;
 }

//Change Medal Count
//Description: The Change Medal Count method is, as its name implies, used to change
//             the medal count for countries which have already been added to the
//             linked list. It does this by searching for a country node in the linked
//             list matching a user-specified country name and medal type. Will return false
//             if the country is not in the list, or is the user specifies a non-existent
//             medal type
bool LinkedList::changeMedalCount(string countryName, string medalType, int count)
{
    string findCountryName = countryName;
    struct Country * currentOnList = NULL;
    string extractName;
    string medal = medalType;

    if (head != NULL)
    {
        currentOnList = head;
        extractName = head->name;
    }
    while (currentOnList != NULL)
    {
        if (findCountryName == extractName)
        {
            if (medal == "Gold" || medal == "gold")
            {
                currentOnList->gold = count;
                return true;
            }
            else if (medal == "Silver" || medal == "silver")
            {
                currentOnList->silver = count;
                return true;
            }
            else if (medal == "Bronze" || medal == "bronze")
            {
                currentOnList->bronze = count;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            currentOnList = currentOnList->next;
            if (currentOnList == NULL)
            {
                return false;
            }
            extractName = currentOnList->name;
        }
    }
    return false;
}

//Print List
//Description: Used to print the contents of the linked list. Prints each country's name, followed
//             by the relevant medal information specified by the user when creating or modifying the
//             country, followed by a new line. When the list is empty, will output "The list is empty"
//             followed by a new line.
void LinkedList::printList()
{
    struct Country * currentPointer = NULL;
    if (head != NULL)
    {
        currentPointer = head;
        currentPointer->next = head->next;

    }
	if (currentPointer == NULL)
	{
		cout << "The list is empty \n";
	}
    else if (currentPointer != NULL && currentPointer->next == NULL)
    {
       cout << "Country Name: " << currentPointer->name << ", Gold: " << currentPointer->gold << ", Silver: " << currentPointer->silver << ", Bronze: " << currentPointer->bronze << endl;
    }
    else
    {
        do
        {
            cout << "Country Name: " << currentPointer->name << ", Gold: " << currentPointer->gold << ", Silver: " << currentPointer->silver << ", Bronze: " << currentPointer->bronze << endl;
            currentPointer = currentPointer->next;
        } while (currentPointer != NULL);
    }
}
