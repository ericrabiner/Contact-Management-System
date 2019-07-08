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
#include "contacts.h"
#include "contactHelpers.h"
#include <string.h>

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name * name) {
	int flag;

	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", (*name).firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	flag = yes();
	if (flag == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", (*name).middleInitial);
		clearKeyboard();
	}
	else
		strcpy((*name).middleInitial, "");

	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", (*name).lastName);
	clearKeyboard();
}

// getAddress:
void getAddress(struct Address * address) {
	int flag;
	int num;
	printf("Please enter the contact's street number: ");
	(*address).streetNumber = getInt();
	num = (*address).streetNumber;
	while (num < 0) {
		printf("Please enter the contact's street number: ");
		(*address).streetNumber = getInt();
		num = (*address).streetNumber;
	}

	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", (*address).street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	flag = yes();

	if (flag == 1) {
		printf("Please enter the contact's apartment number: ");
		(*address).apartmentNumber = getInt();
		num = (*address).apartmentNumber;
		while (num < 0) {
			printf("Please enter the contact's apartment number: ");
			(*address).apartmentNumber = getInt();
			num = (*address).apartmentNumber;
		}
	}
	else
		(*address).apartmentNumber = 0;

	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]", (*address).postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]", (*address).city);
	clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers * numbers) {
	int flag;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone((*numbers).cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	flag = yes();
	if (flag == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone((*numbers).home);
	}
	else
		strcpy((*numbers).home, "");

	printf("Do you want to enter a business phone number? (y or n): ");
	flag = yes();
	if (flag == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone((*numbers).business);
	}
	else
		strcpy((*numbers).business, "");
}

// getContact
void getContact(struct Contact * contact) {
	getName(&(*contact).name);
	getAddress(&(*contact).address);
	getNumbers(&(*contact).numbers);
}