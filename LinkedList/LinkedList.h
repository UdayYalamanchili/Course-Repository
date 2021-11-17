// Assignment #1
// Name: Uday Yalamanchili
// ASU Email Address: uyalaman@asu.edu
// Description: This program builds our own custom data structure by
//              defining the methods addElement, removeElement, printList,
//              constructor and destructor for the class LinkedList.

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings

using namespace std;

//struct Club represents some club information
struct Club
{
    string clubName;
    string univName;
    struct Club * next;
};

//class LinkedList will contains a linked list of clubs
class LinkedList
{
    private:
    struct Club * head;

    public:
    LinkedList();
    ~LinkedList();
    bool addElement(string clubName, string univName, int index);
    bool removeElement(string clubName, string univName);
    void printList();
};

//Constructor to initialize the linked list
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
//Description: Destructor to delete every element in the linked list and free the memory
LinkedList::~LinkedList()
{
    struct Club* select_element = head;  // The current selection in the list
    struct Club* next_element = NULL;   // The next element of the current selection, initialized with NULL
    int k = 0;

    while (select_element != NULL) // deletes each entry starting from head
    {
        next_element = select_element -> next;
        delete select_element;
        select_element = next_element;
        k++;
    }

    head = NULL;

    cout << "The number of deleted clubs is: " << k << "\n" << endl;
}

//Description: This method adds the new club, university information at the desired position in the list with the help of index.
bool LinkedList::addElement(string newClubName, string newUnivName, int index)
 {
    struct Club* head_dummy = new Club();

    if (head == NULL && index == 0 ) // This code helps to insert a new entry as the head of an empty list
    {
        head_dummy -> clubName = newClubName;
        head_dummy -> univName = newUnivName;
        head_dummy -> next = NULL;
        head = head_dummy;
        return true;
    }

    struct Club* dummy = new Club();
    dummy = head;

    struct Club* new_club = new Club();
    new_club -> clubName = newClubName;
    new_club -> univName = newUnivName;

    int i = 0;

    if (index == 0) // This code helps to insert an entry as the head of a non-empty list
    {
        new_club -> next = head;
        head = new_club;
        return true;
    }
    else if (index > 0)
    {
        for(i=0; i < index - 1; i++)
        {
            dummy = dummy -> next;
            if (dummy == NULL)  // Returns false if the index is greater than the length of the list
            {
                return false;
            }
        }
        new_club -> next = dummy -> next;
        dummy -> next = new_club;  // This piece of code helps to insert an entry at any position in the list other than the head
        return true;
    }
    else if ( index < 0 ) // Returns false if the index is negative
        return false;
 }

//Description: This method deletes the existing club, university information from the list based on the provided club, university information.
bool LinkedList::removeElement(string someClubName, string someUnivName)
 {
    //To be completed
    int j = 0;
    struct Club* del_element = new Club();  // The element/selection that will be deleted
    struct Club* prev_element = new Club(); // The element that exists before the to-be deleted selection

    del_element = head;
    prev_element = NULL;

    if (del_element == NULL) // Returns false if it is an empty list
        return false;

    while  (del_element -> clubName != someClubName | del_element -> univName != someUnivName) // iterate till both the club, university names match
    {
        prev_element = del_element;
        del_element = del_element -> next;
        j++;

        if (del_element == NULL) // Returns false, if the del_element reaches NULL before finding a match. No match exists
        {
            return false;
        }
    }

    if (j == 0) // If condition is triggered if the head is the matching element
    {
        head = del_element -> next;
        delete del_element;
        return true;
    }

    else // Entry deletion for every other case
    {
        prev_element -> next = del_element -> next;
        delete del_element;
        return true;
    }
 }

//Description: This method helps print every club, university entry in the list
void LinkedList::printList()
{
    //To be completed
    struct Club* temp = new Club();
    temp = head;

    if (head == NULL)
    {
         cout << "The list is empty" << "\n";
    }

    while (temp != NULL) // iterate and print till the temp pointer reaches the end of list
    {
        cout << "Club Name:" << temp -> clubName << ", " << "University Name:" << temp -> univName << "\n";
        temp = temp -> next;
    }
}
