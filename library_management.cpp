  /*

    Members                      	ID 
1.Mahider Feleke...................ETS 0928/17
2.Marta Kefale.....................ETS 0948/17
3.Mikiyas Mekbib...................ETS 1021/17
4.Nahom Kahase.....................ETS1084/17
5.Nurhassen Mohammed...............ETS1221/17


Objective:
The objective of this program is to create a simple, menu-driven Library Management System
using basic C++ concepts such as arrays, functions, enums, and input validation. 
It allows members to view, search, borrow, and return books, and librarians to add, update, 
and delete books.

Introduction:
This Library Management System simulates real-world library operations in a console environment.
It stores book information (ID, title, author, quantity, status) in parallel arrays and provides
separate menus for members and librarians.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//book status
enum BookStatus {
    AVAILABLE,
    BORROWED
};

const int MAX_BOOKS = 10;

/* Function declaration */
void librariandashboard();
void memberdashboard();
void showMemberMenu();
void showLibrarianMenu();
int input();
void displayBooks(string* id, string* title, string* author, BookStatus* status, int* quantity, int count);
int searchBookByID(string* id, int count, const string &searchID);
void searchBooksTitleAutor(string* id, string* title, string* author, BookStatus* status, int* quantity, int count, const string &query);
bool isValidID(const string &id);
void borrowBook(string* id, BookStatus* status, int* quantity, int count);
void returnBook(string* id, BookStatus* status, int* quantity, int count);
void addBook(string* id, string* title, string* author, BookStatus* status, int* quantity, int& count);
void updateBook(string* id, string* title, string* author, BookStatus* status, int* quantity, int& count);
void deleteBook(string* id, string* title, string* author, BookStatus* status, int* quantity, int& count);
void outputFormat(string* id, string* title, string* author, BookStatus* status, int* quantity, int i);
// variable dicluration
    string bookID[MAX_BOOKS]     = {"AA001", "AA002", "AA003"};
    string bookTitle[MAX_BOOKS]  = {"C++ Basics", "Data Structures", "Algorithms"};
    string bookAuthor[MAX_BOOKS] = {"Bjarne", "Mark", "CLRS"};
    BookStatus status[MAX_BOOKS] = {AVAILABLE, AVAILABLE, BORROWED};
    int quantity[MAX_BOOKS] = {3, 2, 1};
    int availableQuant[MAX_BOOKS]={3,2,1};
    int bookCount = 3;

int main() {
    while (true) {
        cout << "\nLogin as: (1) Member  (2) Librarian (3)Exit : ";
        int role = input();
        if (role == 1) { memberdashboard(); continue; }
        if (role == 2) {
            cout << "\nEnter librarian password: ";
            string pw; getline(cin, pw);
            if (pw == "1234"){ librariandashboard();continue;}else  {cout << "\nIncorrect password. Try again.\n";continue;} 
            
        }
        if(role==3){cout<<"\nExiting program...\n";break;}
        cout << "\nInvalid selection.\n";
    }

    return 0;
}

/* Function Definitions */
void librariandashboard(){
    int choice=-1;
    do{
    showLibrarianMenu();
     choice = input();
        if (choice == -1) { cout << "\nInvalid choice. Please try again.\n"; continue; }
    switch (choice) {
                case 1: displayBooks(bookID, bookTitle, bookAuthor, status, quantity, bookCount); break;
                case 2: {
                    cout << "\nEnter Book ID to search (format AA123): ";
                    string searchID; getline(cin, searchID);
                    if (searchID.empty()) { cout << "\nNo ID entered.\n"; break; }
                    if (!isValidID(searchID)) { cout << "\nInvalid ID format. Expected 'AA' followed by 3 digits (e.g. AA123).\n"; break; }
                    int index = searchBookByID(bookID, bookCount, searchID);
                    if (index == -1) cout << "\nBook not found.\n";
                    else {
                        cout << "\nSearch Result:\n";
                        cout << "Title: " << bookTitle[index] << "\nAuthor: " << bookAuthor[index]
                             << "\nQuantity: " << quantity[index] << "\nStatus: " << (status[index] == AVAILABLE ? "Available" : "Borrowed") << "\n";
                    }
                    break;
                }
                case 3: {
                    cout << "\nEnter title or author to search: ";
                    string q; getline(cin, q);
                    if (q.empty()) { cout << "\nNo search text entered.\n"; break; }
                    searchBooksTitleAutor(bookID, bookTitle, bookAuthor, status, quantity, bookCount, q);
                    break;
                }
                case 4: borrowBook(bookID, status, quantity, bookCount); break;
                case 5: returnBook(bookID, status, quantity, bookCount); break;
                case 6: addBook(bookID, bookTitle, bookAuthor, status, quantity, bookCount); break;
                case 7: updateBook(bookID, bookTitle, bookAuthor, status, quantity, bookCount); break;
                case 8: deleteBook(bookID, bookTitle, bookAuthor, status, quantity, bookCount); break;
                case 9: cout << "\nYou have been loged out...\n"; return;
                default: cout << "\nInvalid choice. Please try again.\n";
            }
        }while(true);
}

void memberdashboard(){
    int choice = -1;
    do{
        showMemberMenu();
        choice = input();
        if (choice == -1) { cout << "\nInvalid choice. Please try again.\n"; continue; }

       
            switch (choice) {
                case 1: displayBooks(bookID, bookTitle, bookAuthor, status, quantity, bookCount); break;
                case 2: {
                    cout << "\nEnter Book ID to search (format AA123): ";
                    string searchID; 
                    getline(cin, searchID);
                    if (searchID.empty()) { cout << "\nNo ID entered.\n"; break; }
                    if (!isValidID(searchID)) { cout << "\nInvalid ID format.(e.g. AA123).\n"; break; }
                    int index = searchBookByID(bookID, bookCount, searchID);
                    if (index == -1) cout << "Book not found.\n";
                    else {
                        cout << "\nSearch Result:\n";
                        cout << "Title: " << bookTitle[index] << "\nAuthor: " << bookAuthor[index]
                             << "\nQuantity: " << quantity[index] << "\nStatus: " << (status[index] == AVAILABLE ? "Available" : "Borrowed") << "\n";
                    }
                    break;
                }
                case 3: {
                    cout << "\nEnter title or author to search: ";
                    string q; getline(cin, q);
                    if (q.empty()) { cout << "\nNo search text entered.\n"; break; }
                    searchBooksTitleAutor(bookID, bookTitle, bookAuthor, status, quantity, bookCount, q);
                    break;
                }
                case 4: borrowBook(bookID, status, quantity, bookCount); break;
                case 5: returnBook(bookID, status, quantity, bookCount); break;
                case 6: cout << "\nYou have been loged out...\n"; return;
                default: cout << "\nInvalid choice. Please try again.\n";
            }
    }while(true);

}


void showMemberMenu() {
    cout << "\n===== Library (Member) =====\n";
    cout << "1. Display all books\n";
    cout << "2. Search book by ID\n";
    cout << "3. Search by title or author\n";
    cout << "4. Borrow a book\n";
    cout << "5. Return a book\n";
    cout << "6. Logout\n";
    cout << "Enter your choice: ";
}

void showLibrarianMenu() {
    cout << "\n===== Library (Librarian) =====\n";
    cout << "1. Display all books\n";
    cout << "2. Search book by ID\n";
    cout << "3. Search by title or author\n";
    cout << "6. Add a new book\n";
    cout << "7. Update a book\n";
    cout << "8. Delete a book\n";
    cout << "9. LogOut\n";
    cout << "Enter your choice: ";
}

//user input
int input(){
    int choice;
    cin>>choice;
    cin.ignore(1000, '\n');
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }
    return choice;
}
// book output format
void outputFormat(string* id, string* title, string* author, BookStatus* status, int* quantity, int i){
    cout<<left<<setw(10)<< id[i]
        <<setw(40)<< title[i]
        <<setw(30)<< author[i]
        <<setw(6)<< quantity[i]
        <<setw(15)<< (status[i] == AVAILABLE ? "Available" : "Borrowed")
        << endl;
}

// List all books
void displayBooks(string* id, string* title, string* author, BookStatus* status, int* quantity, int count) {
    if (count == 0) {
        cout << "\nNo books available.\n";
        return;
    }

    cout << "\n--- Book List ---\n\n";
    cout <<left<<setw(10)<< "ID" <<setw(40)<<"Title"<<setw(30)<<"Author"<<setw(6)<<"Qty"<<setw(15)<<"Status"<<endl;
    for (int i = 0; i < count; i++) {
           outputFormat(id,title,author,status,quantity,i);
    }
}
// search book by ID
int searchBookByID(string* id, int count, const string &searchID) {
    for (int i = 0; i < count; i++) {
        if (id[i] == searchID) return i;
    }
    return -1;
}
// change to lower case to validate user input
void textToLower(string &s) {
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') s[i] = char(c - 'A' + 'a');
    }
}

//ID validation, Must be exactly 5 as a format "AA" followed by 3 numbers
bool isValidID(const string &id) {
    
    if (id.size() != 5) return false;
    if (id[0] != 'A' || id[1] != 'A') return false;
    for (int i = 2; i < 5; ++i) if (id[i] < '0' || id[i] > '9') return false;
    return true;
}

// search book by title or autor
void searchBooksTitleAutor(string* id, string* title, string* author, BookStatus* status, int* quantity, int count, const string &query) {
    string q = query;
    textToLower(q);
    bool found = false;
    for (int i = 0; i < count; ++i) {
        string t = title[i];
        string a = author[i];
        textToLower(t);
        textToLower(a);
        if (t.find(q) != string::npos || a.find(q) != string::npos) {
            cout << "Match: ID=" << id[i] << " | Title=" << title[i] << " | Author=" << author[i]
                 << " | Qty=" << quantity[i] << " | Status=" << (status[i] == AVAILABLE ? "Available" : "Borrowed") << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matches found for '" << query << "'.\n";
}

void borrowBook(string* id, BookStatus* status, int* quantity, int count) {
    cout << "\nEnter Book ID to borrow (format AA123): ";
    string searchID; getline(cin, searchID);
    if (searchID.empty()) { cout << "\nNo ID entered.\n"; return; }
    if (!isValidID(searchID)) { cout << "\nInvalid ID format. Expected 'AA' followed by 3 digits (e.g. AA123).\n"; return; }
    int index = searchBookByID(id, count, searchID);
    if (index == -1) { cout << "\nBook not found.\n"; return; }
    if (quantity[index] <= 0) { cout << "\nNo copies available to borrow.\n"; return; }
    cout << "Borrower name: "; string borrower; getline(cin, borrower);
    quantity[index]--;
    status[index] = (quantity[index] > 0) ? AVAILABLE : BORROWED;
    cout << "\nBook borrowed successfully. Remaining copies: " << quantity[index] << "\n";
}

void returnBook(string* id, BookStatus* status, int* quantity, int count) {
    cout << "\nEnter Book ID to return (format AA123): ";
    string searchID; getline(cin, searchID);
    if (searchID.empty()) { cout << "\nNo ID entered.\n"; return; }
    if (!isValidID(searchID)) { cout << "\nInvalid ID format. Expected 'AA' followed by 3 digits (e.g. AA123).\n"; return; }
    int index = searchBookByID(id, count, searchID);
    if (index == -1) { cout << "\nBook not found.\n"; return; }
    cout << "\nReturner name: "; string r; getline(cin, r);
    quantity[index]++;
    status[index] = AVAILABLE;
    cout << "\nBook returned successfully. Copies now: " << quantity[index] << "\n";
}

void addBook(string* id, string* title, string* author, BookStatus* status, int* quantity, int& count) {
    if (count >= MAX_BOOKS) {
        cout << "\nLibrary is full. Cannot add more books.\n";
        return;
    }

    cout << "\nEnter new Book ID (format AA123): ";
    string newID; getline(cin, newID);
    if (newID.empty()) { cout << "\nNo ID entered. Cancelled.\n"; return; }
    if (!isValidID(newID)) { cout << "\nInvalid ID format. Expected 'AA' + 3 digits (e.g. AA123).\n"; return; }
    if (searchBookByID(id, count, newID) != -1) { cout << "\nBook ID already exists. Book not added.\n"; return; }

    cout << "\nEnter Book Title: "; string newTitle; getline(cin, newTitle);
    if (newTitle.empty()) { cout << "\nNo title entered. Cancelled.\n"; return; }

    cout << "\nEnter Book Author: "; string newAuthor; getline(cin, newAuthor);
    if (newAuthor.empty()) { cout << "\nNo author entered. Cancelled.\n"; return; }

    cout << "\nEnter quantity (number of copies): ";
    string qtyStr; getline(cin, qtyStr);
    int qty = 1;
    if (!qtyStr.empty()) {
        bool valid = true;
        int val = 0;
        for (char c : qtyStr) {
            if (c < '0' || c > '9') { valid = false; break; }
            val = val * 10 + (c - '0');
        }
        if (valid) {
            qty = val;
            if (qty < 0) qty = 1;
        } else {
            cout << "\nInvalid number. Using 1.\n";
            qty = 1;
        }
    }

    id[count] = newID;
    title[count] = newTitle;
    author[count] = newAuthor;
    quantity[count] = qty;
    status[count] = (qty > 0) ? AVAILABLE : BORROWED;
    count++;

    cout << "\nBook added successfully.\n";
}

void updateBook(string* id, string* title, string* author, BookStatus* status, int* quantity, int& count) {
    cout << "\nEnter Book ID to update (format AA123): ";
    string searchID; getline(cin, searchID);
    if (searchID.empty()) { cout << "\nNo ID entered.\n"; return; }
    if (!isValidID(searchID)) { cout << "\nInvalid ID format.\n"; return; }
    int index = searchBookByID(id, count, searchID);
    if (index == -1) { cout << "\nBook not found.\n"; return; }

    cout << "\nEnter new title (leave blank to keep): "; string nt; getline(cin, nt);
    if (!nt.empty()) title[index] = nt;
    cout << "\nEnter new author (leave blank to keep): "; string na; getline(cin, na);
    if (!na.empty()) author[index] = na;
    cout << "\nEnter new quantity (leave blank to keep): "; string nq; getline(cin, nq);
    if (!nq.empty()) {
        try { int v = stoi(nq); if (v >= 0) quantity[index] = v; }
        catch(...) { cout << "\nInvalid number; quantity unchanged.\n"; }
    }
    status[index] = (quantity[index] > 0) ? AVAILABLE : BORROWED;
    cout << "\nBook updated.\n";
}

void deleteBook(string* id, string* title, string* author, BookStatus* status, int* quantity, int& count) {
    cout << "\nEnter Book ID to delete (format AA123): ";
    string searchID; getline(cin, searchID);
    if (searchID.empty()) { cout << "\nNo ID entered.\n"; return; }
    if (!isValidID(searchID)) { cout << "\nInvalid ID format.\n"; return; }
    int index = searchBookByID(id, count, searchID);
    if (index == -1) { cout << "\nBook not found.\n"; return; }
    for (int i = index; i < count - 1; ++i) {
        id[i] = id[i+1];
        title[i] = title[i+1];
        author[i] = author[i+1];
        status[i] = status[i+1];
        quantity[i] = quantity[i+1];
    }
    // clear last
    id[count-1] = "";
    title[count-1] = "";
    author[count-1] = "";
    status[count-1] = AVAILABLE;
    quantity[count-1] = 0;
    count--;
    cout << "\nBook deleted successfully.\n";
}



