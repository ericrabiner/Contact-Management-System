# Contact Management System

An application written in C that can add, update, delete, and sort a contact list.

## Prerequisites
Install the Minimalist GNU for Windows

## Running the Application

Compile the source and header files.
```
g++ contactHelpers.c contacts.c a2ms2.c -o contacts
```

Run the executable file.
```
./contacts.exe
```

Example
```
------------------------------------------
Testing: Final A#2-Milestone #4
------------------------------------------
Contact Management System
-------------------------
1. Display contacts
2. Add a contact
3. Update a contact
4. Delete a contact
5. Search contacts by cell phone number
6. Sort contacts by cell phone number
0. Exit

Select an option:> 1

+-----------------------------------------------------------------------------+
|                              Contacts Listing                               |
+-----------------------------------------------------------------------------+
 Rick Grimes
    C: 4161112222   H: 4162223333   B: 4163334444
       11 Trailer Park, King City, A7A 2J2
 Maggie R. Greene
    C: 9051112222   H: 9052223333   B: 9053334444
       55 Hightop House, Bolton, A9A 3K3
 Morgan A. Jones
    C: 7051112222   H: 7052223333   B: 7053334444
       77 Cottage Lane, Peterborough, C7C 9Q9
 Sasha Williams
    C: 9052223333   H: 9052223333   B: 9054445555
       55 Hightop House, Bolton, A9A 3K3
+-----------------------------------------------------------------------------+
Total contacts: 4

(Press Enter to Continue)
```