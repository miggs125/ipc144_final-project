/* -------------------------------------------
Name: Miguel Roncancio
Student number: 151091170
Email: mroncancio@myseneca.ca
Section:
Date: March 29 2018
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"




// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+
// getName:
void getName(struct Name *name_p){
    int answer;
    //get first name
    printf("Please enter the contact's first name: ");
    scanf(" %[^\n]", (*name_p).firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    clearKeyboard();
    
    answer = yes();
    if(answer){
    //get middle initials/name
        printf("Please enter the contact's middle initial(s): ");
        scanf(" %[^\n]", name_p->middleInitial);
    } else {
        strcpy(name_p->middleInitial, "");
    }

    printf("Please enter the contact's last name: ");
    scanf(" %[^\n]", name_p->lastName);
    
    
};




// getAddress:
void getAddress(struct Address *addressPtr){
    
    //get contacts street number
    printf("Please enter the contact's street number: ");
    addressPtr->streetNumber = getInt();
    //get contact's street

    printf("Please enter the contact's street name: ");
    scanf("%39[^\n]", addressPtr->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    clearKeyboard();
    
    if(yes()){
        printf("Please enter the contact's apartment number: ");
        addressPtr->apartmentNumber = getInt();
    }else {
        addressPtr->apartmentNumber= 0;
    }
    printf("Please enter the contact's postal code: ");
    scanf("%[^\n]", addressPtr->postalCode);
    
    clearKeyboard();
    printf("Please enter the contact's city: ");
    scanf(" %40[^\n]", addressPtr->city); 
};



// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers *numPtr){

    int answer;

    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numPtr->cell); //**********UPDATE*******************

    printf("Do you want to enter a home phone number? (y or n): ");

    answer = yes();

    if(answer){
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numPtr->home);  //**********UPDATE*******************
    } else {
        strcpy(numPtr->home, "");
    }

    printf("Do you want to enter a business phone number? (y or n): ");

    if(yes()){
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numPtr->business); //**********UPDATE*******************
    } else {
        strcpy(numPtr->business, "");
    }


};


// getContact

void getContact(struct Contact *contact){

    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);

};
