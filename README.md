# Contact List Management System

## Group Members
- Alzahraa Abdelhamed - 2300030
- Sama Ali - 2300125
- Mohamed Sherif - 2300482 
- Ziad Mostafa - 2300098
- Kareem Nasser Abdelmageed - 2300775
---

## Project Description
This project is a Contact List Management System developed using C++ and Qt.

The system allows users to:
- add contacts,
- search for contacts,
- update contact information,
- delete contacts,
- display all contacts,
- and save/load contacts using file handling.

The project demonstrates the use of data structures and object-oriented programming concepts.

---

## Data Structures Used

### Map<string, Contact>
Used for storing contacts with names as keys to enable fast search, automatic sorting, and efficient insert and delete operations.

### Vector<Contact>
Used for dynamically storing contacts, search results, and lists of all or sorted contacts.


---

## Features
1. Add Contact
2. Search Contact
3. Update Contact
4. Delete Contact
5. Display All Contacts
6. Save and Load Contacts from File
7. Favorite Contacts

---

## Project Files

- `main.cpp` → application entry point and main windows
- `Contact.*` → contact data model 
- `ContactManager.*` → core contact operations
- `FileManager.*` → file handling operations
- `globals.*` → Holds all the global variables used in the application
- `functions.*` → Holds all the functions used in the application




---

## File Handling
The system stores contacts in files to preserve data after closing the application.

File handling was implemented using:
- `ifstream`
- `ofstream`

---

## Technologies Used
- C++
- Qt6
- CMake

---

## How to Build and Run

### Requirements
- Qt6
- CMake
- C++17 compatible compiler

### Build
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Run

```bash
./ContactList.exe
```
Or use Vscode to run with CMakeTools extension
---

## AI Usage Declaration

AI tools such as claude were used for:
- brainstorming ideas.
- debugging.
- improving code structure.
- improving documentation.

Some AI-generated suggestions were modified to better fit the project requirements and improve code simplicity.

### Example of Incorrect AI Output
There was a bug where AI kept saying that there is a linker error and it turned out that there was an uninitialized pointer that was being accessed.

The final implementation and understanding were completed by the group members.
