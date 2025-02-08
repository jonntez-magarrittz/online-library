Online Library Management System
--------------------------------
This project implements an Online Library Management System using Object-Oriented Programming (OOP) principles in C++. The system allows:

1. Adding books to the library.
2. Adding users to the system.
3. Searching for books by title.
4. Borrowing books (with validation).
5. Returning books (with validation).
6. Running automated tests to validate core functionality.

### How to Compile and Run
1. Ensure you have a C++ compiler installed (e.g., g++).
2. Save the code to a file named `LibraryManagementSystem.cpp`.
3. Open a terminal and navigate to the file's directory.
4. Compile the program: `g++ -o LibraryManagementSystem LibraryManagementSystem.cpp`
5. Run the program: `./LibraryManagementSystem`

### How to Run Tests
- The program includes a `runTests()` function that automatically runs test cases to validate functionalities like searching, borrowing, and returning books.

### Design Choices
1. **Encapsulation:** Each class encapsulates its data and behavior.
2. **Modularity:** Separate classes for `Book`, `User`, and `Library` to promote maintainability.
3. **Validation:** Methods ensure books cannot be borrowed/returned under invalid conditions.
4. **Scalability:** The design can be easily extended to include more features like user authentication, book categories, or advanced search.

### Future Enhancements
- Add a user interface (UI).
- Support for saving and loading data from a database.
- Enhanced search capabilities (e.g., by author or genre).
- Notification system for overdue books.
*/
