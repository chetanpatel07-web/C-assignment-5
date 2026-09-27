#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    float price;

public:
    static int bookCount;

    // Parameterized constructor
    Book(int id, string t, string a, float p) {
        bookId = id;
        title = t;
        author = a;
        price = p;

        bookCount++;
        cout << "Book created. Total books: "
             << bookCount << endl;
    }

    // Copy constructor
    Book(const Book &b) {
        bookId = b.bookId;
        title = b.title;
        author = b.author;
        price = b.price;

        bookCount++;
        cout << "Book copied. Total books: "
             << bookCount << endl;
    }

    // Display function
    void display() const {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }

    // Destructor
    ~Book() {
        bookCount--;
        cout << "Book destroyed. Total books: "
             << bookCount << endl;
    }

    static int getBookCount() {
        return bookCount;
    }
};

// Initialize static member
int Book::bookCount = 0;

int main() {

    Book b1(101, "C++ Programming",
            "Bjarne Stroustrup", 4500);

    b1.display();

    // Copy constructor called
    Book b2(b1);

    b2.display();

    cout << "Total books: "
         << Book::getBookCount() << endl;

    return 0;
}