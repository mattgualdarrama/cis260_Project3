//file: main.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Department.h"

using namespace std;
char InputScrub();
void PrintMenu();
bool ContScrub();

int main()
{
  Department<string> dept1("test");
  char choice;
  bool success;
  do{
    PrintMenu();
    choice = InputScrub();
    switch (choice)
    {
      case '1':
      case 'A':
              success = dept1.Add();
              if (success)
                cout << "\n\nEmployee Added\n\n";
              else  
                cout << "\n\nFailed to add Employee\n\n";
              break;
      case '2':
      case 'R':
              success = dept1.Remove();
              if (success)
                cout << "\nSpecified ID removed.\n";
              else 
                cout << "\nCould not remove specified ID.\n";
              break;
      case '3':
      case 'C':
              dept1.Clear();
      case '4':
      case 'P':
              if (dept1.GetCount() == 0)
                cout << "No data to print\n";
              else
                dept1.Print(dept1.GetCount()); 
              break;         
    }
  } while (ContScrub());
}

    /** A function that displays the menu to the user, does not take any input or arguments.
    */
void PrintMenu()
{
  system("CLS");  
  cout <<setw(30)<< " Main Menu\n\n\n";   // menu of options to add/remove or clear
  cout << setw(15)<< " "<< "(1)- (A)dd\n\n"; // data is enterd from within Add
  cout << setw(15)<< " "<< "(2)- (R)emove \n\n"; // the id to remove is entered in Remove.
  cout << setw(15)<< " "<< "(3)- (C)lear\n\n";
  cout << setw(15)<< " "<< "(4)- (P)rint \n\n\n";
  cout << setw(35)<< "Enter Choice:\t";
}

/**
 * A function to test the user input.  
 * @pre None.
 * @post Return user input if valid
 * @return Valid input
 */
char InputScrub()
{
  char choice;
  bool scrubbed = 0;
  cin>>choice;

  while (!scrubbed)
  {
    choice = toupper(choice);
    if (choice == '1' ||  choice == 'A' || choice == '2' || choice == 'R' || 
        choice == '3' || choice == 'C' || choice == '4' || choice == 'P')
      scrubbed = 1;
    else
    {
      cout << setw(35)<< "Invalid Choice, try again:\t"; cin>>choice;
    }
  }
  return choice;
}

/**
 * A function to test the user input.  
 * @pre None.
 * @post Return user input if valid
 * @return Valid input
 */
bool ContScrub()
{
  char choice;
  bool scrubbed = 0;
  cout << "Continue? (y/n):\t"; cin>>choice;

  while(!scrubbed)
  {
    choice = toupper(choice);
    if (choice == 'Y')
    {
      scrubbed = 1;
      return 1;
    }
    else if (choice == 'N')
    {
      scrubbed = 1;
      return 0;
    }
    else
    {
      cout << "Invalid input, try again:\t";
      cin >> choice;
    }
  }
  return 0; //prevents control may reach end of non-void warning
}
