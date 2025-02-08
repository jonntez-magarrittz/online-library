// Online Library Management System
// Author: Onesmus Okune
// Date: 08/02/2025

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Book class definition
class Book {
private:
    string title;
    string author;
    int id;
    bool isBorrowed;

public:
    Book(int id, const string &title, const string &author)
        : id(id), title(title), author(author), isBorrowed(false) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getBorrowedStatus() const { return isBorrowed; }

    void borrowBook() { isBorrowed = true; }
    void returnBook() { isBorrowed = false; }
};

// User class definition
class User {
private:
    string name;
    int userId;
    vector<int> borrowedBooks;

public:
    User(int userId, const string &name) : userId(userId), name(name) {}

    int getUserId() const { return userId; }
    string getName() const { return name; }

    void borrowBook(int bookId) { borrowedBooks.push_back(bookId); }
    void returnBook(int bookId) {
        borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), bookId), borrowedBooks.end());
    }
};

// Library class definition
class Library {
private:
    vector<Book> books;
    vector<User> users;

public:
    void addBook(const Book &book) { books.push_back(book); }

    void addUser(const User &user) { users.push_back(user); }

    void searchBookByTitle(const string &title) {
        for (const auto &book : books) {
            if (book.getTitle() == title) {
                cout << "Book Found: " << book.getTitle() << " by " << book.getAuthor() << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void borrowBook(int userId, int bookId) {
        auto userIt = find_if(users.begin(), users.end(), [&userId](const User &u) { return u.getUserId() == userId; });
        auto bookIt = find_if(books.begin(), books.end(), [&bookId](const Book &b) { return b.getId() == bookId; });

        if (userIt != users.end() && bookIt != books.end() && !bookIt->getBorrowedStatus()) {
            bookIt->borrowBook();
            userIt->borrowBook(bookId);
            cout << "Book borrowed successfully." << endl;
        } else {
            cout << "Cannot borrow the book." << endl;
        }
    }

    void returnBook(int userId, int bookId) {
        auto userIt = find_if(users.begin(), users.end(), [&userId](const User &u) { return u.getUserId() == userId; });
        auto bookIt = find_if(books.begin(), books.end(), [&bookId](const Book &b) { return b.getId() == bookId; });

        if (userIt != users.end() && bookIt != books.end() && bookIt->getBorrowedStatus()) {
            bookIt->returnBook();
            userIt->returnBook(bookId);
            cout << "Book returned successfully." << endl;
        } else {
            cout << "Cannot return the book." << endl;
        }
    }
};

void runTests() {
    Library library;

    // Adding books
    library.addBook(Book(1, "Alice's Adventures in Wonderland", "Lewis Carroll"));
    library.addBook(Book(2, "Pride and Prejudice", "Jane Austen"));

    // Adding users
    library.addUser(User(1, "Lewis"));
    library.addUser(User(2, "Jane"));

    // Test: Search for a book that exists
    cout << "\nTest: Search for 'Alice's Adventures in Wonderland'\n";
    library.searchBookByTitle("Alice's Adventures in Wonderland");

    // Test: Search for a book that doesn't exist
    cout << "\nTest: Search for 'Treasure Island'\n";
    library.searchBookByTitle("Treasure Island");

    // Test: Borrow a book successfully
    cout << "\nTest: Borrow 'Alice's Adventures in Wonderland' by Lewis\n";
    library.borrowBook(1, 1);

    // Test: Attempt to borrow an already borrowed book
    cout << "\nTest: Borrow 'Alice's Adventures in Wonderland' by Michael\n";
    library.borrowBook(2, 1);

    // Test: Return a book successfully
    cout << "\nTest: Return 'Alice's Adventures in Wonderland' by Lewis\n";
    library.returnBook(1, 1);

    // Test: Attempt to return a book that is not borrowed
    cout << "\nTest: Return 'Alice's Adventures in Wonderland' by Michael\n";
    library.returnBook(2, 1);
}

int main() {
    runTests();
    return 0;
}
