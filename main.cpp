#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book class
class Book {
private:
    string title;
    string author;
    int id;
    bool isAvailable;

public:
    Book(int id, string title, string author) : id(id), title(title), author(author), isAvailable(true) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getAvailability() const { return isAvailable; }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Book \"" << title << "\" borrowed successfully.\n";
        } else {
            cout << "Book \"" << title << "\" is not available.\n";
        }
    }

    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Book \"" << title << "\" returned successfully.\n";
        } else {
            cout << "Book \"" << title << "\" was not borrowed.\n";
        }
    }
};

// Library class
class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book \"" << book.getTitle() << "\" added to the library.\n";
    }

    void listBooks() const {
        cout << "Books in the library:\n";
        for (const auto& book : books) {
            cout << "ID: " << book.getId() << ", Title: " << book.getTitle()
                 << ", Author: " << book.getAuthor()
                 << ", Available: " << (book.getAvailability() ? "Yes" : "No") << endl;
        }
    }

    void borrowBook(int id) {
        for (auto& book : books) {
            if (book.getId() == id) {
                book.borrowBook();
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    void returnBook(int id) {
        for (auto& book : books) {
            if (book.getId() == id) {
                book.returnBook();
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }
};

// Main function
int main() {
    Library library;

    // Adding books to the library
    library.addBook(Book(1, "1984", "George Orwell"));
    library.addBook(Book(2, "To Kill a Mockingbird", "Harper Lee"));
    library.addBook(Book(3, "The Great Gatsby", "F. Scott Fitzgerald"));

    // Listing all books
    library.listBooks();

    // Borrowing and returning books
    library.borrowBook(1);
    library.borrowBook(2);
    library.returnBook(1);
    library.borrowBook(3);
    library.returnBook(4); // Invalid ID

    // Listing books after operations
    library.listBooks();

    return 0;
}