**Library Management System (C++)**

Console-based Library Management System implemented as a single-file C++ program.

**Implemented features**
- Role-based menus: Member and Librarian (password protected)
- Display all books with ID / Title / Author / Quantity / Status
- Search by ID (format: AA123)
- Search by title or author (case-insensitive substring match)
- Borrow and return books (updates quantity and status)
- Add, update, and delete books (Librarian only)

**Defaults & data layout**
- Stored in parallel arrays: `bookID`, `bookTitle`, `bookAuthor`, `status`, `quantity`
- Maximum books: `MAX_BOOKS = 10`
- Program ships with 3 sample books (IDs: AA001, AA002, AA003)
- Default librarian password: `1234`
        
**User Roles**

*The system supports two types of users:*

1. Member

  View all books

  Search books by ID
  
  Search books by title or author
  
  Borrow books
  
  Return books

2. Librarian (password protected)

  View all books
  
  Search books
  
  Add new books
  
  Update existing books
  
  Delete books
  
  Borrow / return books

Default librarian password: 1234

**Key Concepts Used**

This project demonstrates:

  Arrays and array manipulation
  
  Functions and parameter passing
  
  Pointers (string*, int*)
  
  Enumerations (enum)
  
  Input validation
  
  Menu-driven programs
  
  Searching algorithms
  
  Updating and deleting records
  
  String processing
  
  Console formatting (iomanip)
  
  Basic access control (member vs librarian)
  

**Project Structure**

main.cpp

│

├── Menu display functions

├── Input validation

├── Book search functions

├── Borrow / return logic

├── Add / update / delete book logic

├── Helper formatting functions

└── Main program loop

**Build & run**
 - Using the provided VS Code task `C/C++: gcc.exe build active file` (recommended):

```powershell
# builds the active .cpp file into an .exe (Windows/MSYS2)
C:\msys64\ucrt64\bin\g++.exe -fdiagnostics-color=always -g library_management.cpp -o library_management.exe
.
```

 - Or build manually with `g++`:

```powershell
g++ -g library_management.cpp -o library_management.exe
.
```

**Usage**
- Run the compiled executable. You'll be prompted to choose a role:
  - Enter `1` for Member, `2` for Librarian, `3` to Exit.
- If choosing Librarian you'll be asked for the password (`1234`).
- Follow on-screen menus to perform operations. IDs must follow the format `AA` + 3 digits (e.g. `AA123`).

Code notes
- File: `library_management.cpp`
- Key constants: `MAX_BOOKS = 10`
- Status enum: `AVAILABLE` / `BORROWED`
- Input validation is implemented for numeric menu input and ID format checks.
