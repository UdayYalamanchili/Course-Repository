// Assignment #5
// Name: Uday Yalamanchili
// ASU Email Address: uyalaman@asu.edu
// Description: The below program displays a menu of various choices to the user
//        and performs the selected task. It keeps asking the user to
//        enter their choice until the choice 'Q' (Quit) is selected.

#include <iostream>
#include <string> 
#include "HashTable.h"

using namespace std;

void printMenu();

int main()
{
  // local variables, can be accessed anywhere from the main method
  int hashSize, result, count, k = 0;
  int credits, capacity, cap, comma;
  char input1 = 'Z';
  bool success = false;
  string courseInfo, info, id, temp;
  string courseId, date, days, time, str[5], str1[2];

  printMenu();

  cout << "Please enter a hash table size\n";
  cin >> hashSize;
  cin.ignore(20, '\n'); //flush the buffer

  // instantiate a Hash Table object
  HashTable * ht = new HashTable(hashSize);
 
  do  // will ask for user input
  {
      cout << "What action would you like to perform?\n";
      cin.get(input1);
      input1 = toupper(input1);
      cin.ignore(20, '\n'); //flush the buffer

      // matches one of the case statement
      switch (input1)
      {
        case 'A':   //Add Course Information
          cout << "Enter a course information using the format courseId:credits:capacity:days,time\n";
          getline(cin, courseInfo);
          k = 0;
          temp = "";
          comma = 0;
          credits = 0;
          capacity = 0;
          courseId = "";
          days = "";
          time = "";
          
          for(int i = 0; i < 5; i++)
          {
            str[i] = "";
          }

          for(int i = 0; i < courseInfo.length(); i++)
          {
              if(courseInfo[i]==':')
              {   
                  k++;
                  temp="";
              }
              else
              {
                if(courseInfo[i] != ',')
                {
                  temp = temp+courseInfo[i];
                }
              }

              str[k]=temp;

              if(courseInfo[i] == ',')
              {
                comma = i;
                break;
              }
          }  

          temp = "";

          for(int i = comma; i < courseInfo.length(); i++)
          {
             if(courseInfo[i]==',')
              {   
                  k++;
                  temp="";
              }
              else
              {
                  temp = temp+courseInfo[i];
              }

              str[k]=temp;
          }

          courseId = str[0];
          if (str[1] != "")
            credits = stoi(str[1]);
          if (str[2] != "")
            capacity = stoi(str[2]);
          days = str[3];
          time = str[4];

          result = ht->insertElement(courseId, credits, capacity, days, time, hashSize);

          if (result == 1)
          cout << "Information about course " << courseId << " has been added\n";
          else if (result == 0)
          cout << "Information about course " << courseId << " has not been added\n";
          else
          cout << "The table is full\n";
          break;
        case 'B': // Search Course
          cout << "Enter a courseId:\n";
          getline(cin, courseId);
          //courseId = str_upper(courseId);
          ht->searchElement(courseId);
          break;
        case 'C': // Change Course Capacity
          cout << "Enter a courseId and a capacity value to change to using the format courseId:capacity\n";
          getline(cin, info);
          k = 0;
          temp = "";
          id = "";
          cap = 0;
          for(int i=0;i<info.length();i++)
          {
              if(info[i]==':')
              {
                  k++;
                  temp="";
              }
              else
              {
                  temp = temp+info[i];
              }
              str1[k]=temp;
          }  

          id = str1[0];
          cap = stoi(str1[1]);

          success = ht->changeElement(id, cap);
          if (success == true)
            cout << id << " updated\n";
          else
            cout << id << " not found\n";
          break;
        case 'D':   //Display Course Information
          ht->printable();
          break;
        case 'Q':   //Quit
          delete ht;
          break;
        case '?':   //Display Menu
          printMenu();
          break;
        default:
          cout << "Unknown action\n";
          break;
      }
  } 
  
  while (input1 != 'Q');

  return 0;
}


/** The method printMenu displays the menu to a user**/
void printMenu()
{
    cout << "Choice\t\tAction\n";
    cout << "------\t\t------\n";
    cout << "A\t\tAdd Course Information\n";
    cout << "B\t\tSearch Course Information\n";
    cout << "C\t\tChange Course Capacity\n";
    cout << "D\t\tPrint Course Information\n";
    cout << "Q\t\tQuit\n";
    cout << "?\t\tDisplay Help\n\n";
}


