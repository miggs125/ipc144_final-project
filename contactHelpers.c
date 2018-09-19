/* -------------------------------------------
Name: Miguel Roncancio   
Student number:  151091170
Email: mroncancio@myseneca.ca          
Section:        
Date: March 29 2018   
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#define MAXCONTACTS 5

#include <stdio.h>
#include <stdlib.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        function definitions below...            |
// +-------------------------------------------------+
// clearKeyboard:  Empty function definition 
void clearKeyboard(void){
    int ch;
    while ((ch = getchar() != '\n') && ch != EOF);    
}

// pause: Empty function definition goes here:
void pause(void){

    printf("(Press Enter to Continue)\n");
    clearKeyboard();

};


// getInt: Empty function definition goes here:
int getInt(void){

    int num;
    char valid;
    do{
        
        scanf("%d%c",&num,&valid);
        if(valid != '\n'){ //check if scanf successfully scanned 2 values and is of integer type
            clearKeyboard(); 
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }        

    }while(valid != '\n');

    return num;
};


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max){

    int num = getInt();

    if(num > max || num < min){
        while(num > max || num < min){
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
            num = getInt();

        }
        

    }    

    return num;
};


// yes: Empty function definition goes here:
int yes(void){

    char *answer = malloc(sizeof(char)*20);
    int value = 0, length, flag = 1;

    do{
        
        scanf(" %[^\n]", answer);
        length = strlen(answer);

        if((answer[0] == 'y' || answer[0] == 'n' || answer[0] == 'N' || answer[0] == 'Y') && length == 1){ // if proper input, exit loop
            flag = 0; // exit loop
            }else{

            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: "); 
            clearKeyboard();
        }

    } while(flag);
    
    if(answer[0] == 'y' || answer[0] == 'Y'){
        value = 1;
    
    }
     
    clearKeyboard();
    free(answer);
    return value;
};


// menu: Empty function definition goes here:
int menu(void){


    int option;

    printf("Contact Management System\n");
    printf("-------------------------\n");

    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");

    printf("Select an option:> ");
    option = getIntInRange(0,6);

    printf("\n");

    return option;
};

//contact manager system
void ContactManagerSystem(void){
    
    struct Contact contacts[MAXCONTACTS] = { 
        { 
            { "Rick", {'\0'}, "Grimes" },
            { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
            { "4161112222", "4162223333", "4163334444" } 
        },

        {
            { "Maggie", "R.", "Greene" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9051112222", "9052223333", "9053334444" } 
        },

        {
            { "Morgan", "A.", "Jones" },
            { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
            { "7051112222", "7052223333", "7053334444" } 
        },

        {
            { "Sasha", {'\0'}, "Williams" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9052223333", "9052223333", "9054445555" } 
        },
        {        
            {{'\0'},{'\0'},{'\0'}},
            {0,{'\0'}, 0,{'\0'},{'\0'}},
            {{'\0'},{'\0'},{'\0'}}
        }

    };
    
    int option;
    int flag = 1;

    while(flag){
        option = menu();

        switch(option){
            case 1:
                    displayContacts(contacts, MAXCONTACTS);
                    break;
            case 2:
                    addContact(contacts, MAXCONTACTS);
                    break;
            case 3:
                    updateContact(contacts, MAXCONTACTS);
                    break;
            case 4:
                    deleteContact(contacts, MAXCONTACTS);
                    break;
            case 5:
                    searchContacts(contacts, MAXCONTACTS);
                    break;
            case 6:
                    sortContacts(contacts, MAXCONTACTS);
                    break;
		printf("\n");
                break;
            case 0:
                printf("Exit the program? (Y)es/(N)o: ");
                if(yes()){
                    printf("\nContact Management System: terminated");
                    flag = 0;
                }
		printf("\n");
        }
    }
};



// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
//************************UPDATE TO ENSURE ALL VALUES ENTERED ARE NUMERICAL DIGITS****************************************
void getTenDigitPhone(char telNum[]){
    int needInput = 1;
    int i; //loop index
    int flag; // for loop flag

    while (needInput == 1) {
        
        do{
            flag = 0;
            scanf("%10s", telNum);
            
            
            for(i = 0; i < strlen(telNum) && !flag; i++){

                if(telNum[i] < 48 || telNum[i] > 57){
                    printf("Error, all values must be numerical. Enter a 10-digit phone number: ");
                    clearKeyboard();
                    flag = 1; // exit for loop, engages do while loop condition
                }
            }
        
        } while(flag); // while flag == 1 

        // (String Length Function: validate entry of 10 characters)
        
        
        if (strlen(telNum) == 10){            
            needInput = 0;
        }
            
        else
            printf("Enter a 10-digit phone number: ");
            clearKeyboard();
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]){

    int i; //for loop index -- contact
    int index = -1; //return variable for function set to -1 (contact not found, value changes in function if search is successful)
    int flag = 1;
    int comparison;
    
    for(i = 0; i < size && flag; i++){ //loop through each contact
        
        comparison = strcmp(cellNum,contacts[i].numbers.cell);

        if(comparison == 0){ //if strings are the same
            index = i;
            flag = 0; // exit for loop, match found
        }
    }


    return index;
};


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void){

    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
    
};

void displayContactFooter(int size){

    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", size);  
};


void displayContact(const struct Contact *contact){

    //conditional for displaying with/without middle initial
    if(contact->name.middleInitial[0] == 0 ){
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    } else {
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    }
    printf("    C: %-10s   H: %-10s   B: %-10s\n",contact->numbers.cell,contact->numbers.home,contact->numbers.business);

 //conditional for displaying with/without apartment numbers
    if(contact->address.apartmentNumber){
        printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
    } else{
        printf("       %d %s, %s, %s\n", (*contact).address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
        }
    

};

void displayContacts(const struct Contact contacts[], int size){

    int i; //for loop index
    int counter = 0; //count the valid contacts
    
    displayContactHeader(); 

    for(i = 0; i < size; i++){ //iterate through all contacts 
        
        if(strlen(contacts[i].numbers.cell)){   //check for valid contact, look for a cellphone number 
            counter++;  
            displayContact(&contacts[i]);   
        }
    }


    displayContactFooter(counter);
    pause();
};

void searchContacts(const struct Contact contacts[],int size){
    
    char cellNumber[11];
    int j;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNumber);
    printf("\n");
    
    j = findContactIndex(contacts,size,cellNumber);
    
    if(j > -1){
        displayContact(&contacts[j]);
	printf("\n");
    } else {
        printf("*** Contact NOT FOUND ***\n");
    }

    pause();


};

void addContact(struct Contact contacts[], int size){

    int i; // for loop index
    int flag = 1; //for loop flag
    int index = -1;

    for(i = 0; i < size && flag; i++){ //iterate through all contacts 
            
    if(!strlen(contacts[i].numbers.cell)){   //check for open contact space, look for a cellphone number
            index = i; // store index of open space
            flag = 0; //exit loop
        }
    }

    if(index > -1){
        getContact(&contacts[index]);
        printf("--- New contact added! ---\n");
    } else {
        printf("*** ERROR: The contact list is full! ***\n");

    }

    pause();



};

void updateContact(struct Contact contacts[], int size){
    
    char cellNumber[11];
    int index;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNumber);

    index = findContactIndex(contacts,size,cellNumber);
    
    if(index > -1){
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        
        printf("Do you want to update the name? (y or n): ");
        
        if(yes()){
            getName(&contacts[index].name);

        }
        
        printf("Do you want to update the address? (y or n): ");
        
        if(yes()){
            //clearKeyboard();
            getAddress(&contacts[index].address);

        }

        printf("Do you want to update the numbers? (y or n): ");
        
        if(yes()){
            //clearKeyboard();
            getNumbers(&contacts[index].numbers);

        }

        printf("--- Contact Updated! ---\n");
    } else {
        printf("*** Contact NOT FOUND ***\n");
    }

    pause();

};

void deleteContact(struct Contact contacts[], int size){
    char cellNumber[11];
    int index;

    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(cellNumber);
    printf("\n");
    
    index = findContactIndex(contacts,size,cellNumber);
    
    if(index > -1){
        printf("Contact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        
        printf("CONFIRM: Delete this contact? (y or n): ");
        
        if(yes()){
            *contacts[index].numbers.cell = '\0';
            printf("--- Contact deleted! ---\n");
        }
        
        pause();
    }

};

void sortContacts(struct Contact contacts[], int size){

    int i;
    int j;

    struct Contact temp;


    for(i = size -1; i > 0; i--){
        for(j = 0; j < i; j++){    
            if (strcmp(contacts[j].numbers.cell, contacts[j+1].numbers.cell)>0){
                temp = contacts[j];
                contacts[j] = contacts[j+1];
                contacts[j+1] = temp;

            }


        }
    }

    printf("--- Contacts sorted! ---\n");
    pause();
};


