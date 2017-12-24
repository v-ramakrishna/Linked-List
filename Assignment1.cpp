// Assignment #1
// Name:
// ASU ID:
// ASU Email Address:
// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void printMenu();

int main()
   {
       // local variables, can be accessed anywhere from the main method
       char input1 = 'Z';
       string inputInfo;
       string countryName, medalType;
       int gold, silver, bronze, count;
       string line;
       bool success = false;

       // instantiate a Linked List object
       LinkedList * list1 = new LinkedList();

       printMenu();


       do  // will ask for user input
        {
           cout << "\nWhat action would you like to perform?\n";
           cin.get(input1);
           input1 = toupper(input1);
           cin.ignore(20, '\n'); //flush the buffer
           // matches one of the case statement
           switch (input1)
            {
             case 'A':   //Add Country
               cout << "Please enter some country information:\n";
               cout << "Enter a country name:\n";
               getline(cin, countryName);

               cout << "Enter its number of gold medals:\n";
               cin >> gold;
               cin.ignore(20, '\n'); //flush the buffer

               cout << "Enter its number of silver medals:\n";
               cin >> silver;
               cin.ignore(20, '\n'); //flush the buffer
                    
               cout << "Enter its number of bronze medals:\n";
               cin >> bronze;
               cin.ignore(20, '\n'); //flush the buffer

               success = list1->addCountry(countryName, gold, silver, bronze);
     
               if (success == true)
                cout << "The country " << countryName << " added\n";
               else
                cout << "The country " << countryName << " not added\n";
               break;
             case 'D':   //Display Countries
               list1->printList();
               break;
             case 'M':  //Change Medal Count
                cout << "Please enter a country to change its medal count:\n";
                getline(cin, countryName);
                cout << "Please enter a medal type (gold, silver, or bronze):\n";
                getline(cin, medalType);
                cout << "Enter its new medal count:\n";
                cin >> count;
                cin.ignore(20, '\n'); //flush the buffer
                    
                success = list1->changeMedalCount(countryName, medalType, count);
                if (success == true)
                        cout << "The country " << countryName << " updated\n";
                else
                        cout << "The country " << countryName << " does not exist\n";
                break;
                case 'Q':   //Quit
               delete list1;
               break;
             case 'R':  //Remove Country
               cout << "Please enter a country to remove:\n";
               getline(cin, countryName);

               success = list1->removeCountry(countryName);
               if (success == true)
                cout << "The country " << countryName << " removed\n";
               else
                cout << "The country " << countryName << " does not exist\n";
               break;
             case '?':   //Display Menu
               printMenu();
               break;
             default:
               cout << "Unknown action\n";
               break;
            }

        } while (input1 != 'Q');

      return 0;
   }


  /** The method printMenu displays the menu to a user**/
  void printMenu()
   {
     cout << "Choice\t\tAction\n";
     cout << "------\t\t------\n";
     cout << "A\t\tAdd Country\n";
     cout << "D\t\tDisplay Countries\n";
     cout << "M\t\tChange Medal Count\n";
     cout << "Q\t\tQuit\n";
     cout << "R\t\tRemove Country\n";
     cout << "?\t\tDisplay Help\n\n";
  }



