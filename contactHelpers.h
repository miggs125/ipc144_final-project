/* ------------------------------------------------------------------
Name: Miguel Roncancio 
Student number: 151091170
Email: mroncancio@myseneca.ca
Section:
Date: March 29 2018
---------------------------------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
help reduce redundant coding for common repetative tasks.
---------------------------------------------------------------------*/


// Hint:  This header file now has functions with parameters referring to 
//        the struct Contact type so be sure to include the contacts.h header:

#include "contacts.h" 

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function prototypes below...             |
// +-------------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);

// getInt:
// Put function prototype below:
int getInt();

// getIntInRange:
// Put function prototype below:
int getIntInRange(int, int);

// yes:
// Put function prototype below:
int yes(void);

// menu:
// Put function prototype below:
int menu(void);

// ContactManagerSystem:
// Put function prototype below:

void ContactManagerSystem(void);



// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put new function prototypes below...            |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact[], int, const char[]);




void displayContactHeader(void);

void displayContactFooter(int);


void displayContact(const struct Contact*);

void displayContacts(const struct Contact[], int);

void searchContacts(const struct Contact[],int);

void addContact(struct Contact[], int);

void updateContact(struct Contact[], int);

void deleteContact(struct Contact[], int);

void sortContacts(struct Contact[], int);
