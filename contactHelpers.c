/* -------------------------------------------
Name: Eric Rabiner
Student number: 038806063
Email: erabiner@myseneca.ca
Section: L
Date: Tuesday, Nov. 13, 2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contacts.h"
#include "contactHelpers.h"

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("\n");
	printf("(Press Enter to Continue)");
	clearKeyboard();
	printf("\n");
}

// getInt:
int getInt(void)
{
	char NL = 'x';
	int value;
	while (NL != '\n') {
		scanf("%d%c", &value, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return value;
}

// getIntInRange:
int getIntInRange(int param1, int param2)
{
	int value = getInt();
	while (value < param1 || value > param2) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", param1, param2);
		value = getInt();
	}
	return value;
}

// yes:
int yes(void)
{
	char NL = 'x';
	char value;
	while ((NL != '\n') || (!(value == 'y' || value == 'Y' || value == 'n' || value == 'N'))) {
		scanf("%c%c", &value, &NL);
		if ((NL != '\n') || (!(value == 'y' || value == 'Y' || value == 'n' || value == 'N'))) {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
	}
	if (value == 'y' || value == 'Y') {
		return 1;
	}
	else
		return 0;
}

// menu:
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\nSelect an option:> ");

	return getIntInRange(0, 6);
}

// contactManagerSystem:
void contactManagerSystem(void)
{
	struct Contact contacts[MAXCONTACTS] = { 
											{ { "Rick", {'\0'}, "Grimes" }, { 11, "Trailer Park", 0, "A7A 2J2", "King City" }, { "4161112222", "4162223333", "4163334444" } },
											{ { "Maggie", "R.", "Greene" },{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9051112222", "9052223333", "9053334444" } },
											{ { "Morgan", "A.", "Jones" }, { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" }, { "7051112222", "7052223333", "7053334444" } }, 
											{ { "Sasha", {'\0'}, "Williams" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9052223333", "9052223333", "9054445555" } },
	};

	int value = 0;
	while (value != 1) {
		int option = menu();
		if (option > 0 && option <= 6) {
			switch (option) {
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
			}
		}
		else {
			printf("\nExit the program? (Y)es/(N)o: ");
			value = yes();
			printf("\n");
		}
	}
	printf("Contact Management System: terminated\n");
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int i, needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();
		int isNumDigit = 1;
		// Check if all values in telNum are numerical digits
		for (i = 0; i < strlen(telNum); i++) {
			if (isdigit(telNum[i]) == 0) {
				isNumDigit = 0;
			}
		}
		// (String Length Function: validate entry of 10 characters)
		if (isNumDigit == 1 && strlen(telNum) == 10) 
			needInput = 0;
		else {
			printf("Enter a 10-digit phone number: ");
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, index = -1;
	for (i = 0; i < size; i++) {
		if (strcmp(cellNum, contacts[i].numbers.cell) == 0)
			index = i;
	}
	return index;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("\n+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int numberContacts)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d", numberContacts);
}

// displayContact:
void displayContact(const struct Contact * contact)
{
	printf(" %s", contact->name.firstName);
	if (strcmp(contact->name.middleInitial, ""))
		printf(" %s", contact->name.middleInitial);
	printf(" %s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0)
		printf("Apt# %d, ", contact->address.apartmentNumber);
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contact[], int size)
{
	displayContactHeader();
	int i, totalContacts = 0;
	for (i = 0; i < size; i++) {
		if (strcmp(contact[i].numbers.cell, "")) {
			displayContact(&contact[i]);
			totalContacts++;
		}
	}
	displayContactFooter(totalContacts);
	printf("\n");
	pause();

}

// searchContacts:
void searchContacts(const struct Contact contact[], int size)
{
	char cellNum[11];
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	int index = findContactIndex(contact, size, cellNum);
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
		pause();
	}
	else {
		printf("\n");
		displayContact(&contact[index]);
		pause();
	}
}

// addContact:
void addContact(struct Contact contact[], int size)
{
	int i, emptySlot = 0, index;
	for (i = 0; i < size; i++) {
		if (emptySlot == 0 && strlen(contact[i].numbers.cell) == 0) {
			emptySlot = 1;
			index = i;
		}
	}
	if (emptySlot == 1) {
		printf("\n");
		getContact(&contact[index]);
		printf("--- New contact added! ---\n");
		pause();
	}
	else {
		printf("\n*** ERROR: The contact list is full! ***\n");
		pause();
	}
}


// updateContact:
void updateContact(struct Contact contact[], int size) 
{
	char cellNum[11];
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	int index = findContactIndex(contact, size, cellNum);
	if (index == -1) {
		printf("*** Contact NOT FOUND ***\n");
		pause();
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contact[index]);
		printf("\nDo you want to update the name? (y or n): ");
		int value = yes();
		if (value == 1)
			getName(&contact[index].name);
		printf("Do you want to update the address? (y or n): ");
		value = yes();
		if (value == 1)
			getAddress(&contact[index].address);
		printf("Do you want to update the numbers? (y or n): ");
		value = yes();
		if (value == 1)
			getNumbers(&contact[index].numbers);
		printf("--- Contact Updated! ---\n");
		pause();
	}
}


// deleteContact:
void deleteContact(struct Contact contact[], int size)
{
	char cellNum[11];
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	int index = findContactIndex(contact, size, cellNum);
	if (index == -1)
		printf("*** Contact NOT FOUND ***\n");
	else {
		printf("\nContact found:\n");
		displayContact(&contact[index]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");
		int value = yes();
		if (value == 1) {
			strcpy(contact[index].numbers.cell, "");
			printf("--- Contact deleted! ---\n");
		}
	}
	pause();
}

// sortContacts:
void sortContacts(struct Contact contact[], int size)
{
	int i, j;
	struct Contact temp;
	for (i = MAXCONTACTS - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strcmp(contact[j].numbers.cell, contact[j + 1].numbers.cell) > 0) {
				temp = contact[j];
				contact[j] = contact[j + 1];
				contact[j + 1] = temp;
			}
		}
	}
	printf("\n--- Contacts sorted! ---\n");
	pause();
}