# Contact List Management System

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
