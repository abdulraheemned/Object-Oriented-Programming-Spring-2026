//4. Some of the characteristics of a book are the title, author(s), publisher, ISBN, price,
//and year of publication. Design a class bookType that defines the book as an ADT.
//? Each object of the class bookType can hold the following information about a
//book: title, up to four authors, publisher, ISBN, price, and number of copies in
//stock. To keep track of the number of authors, add another member variable.
//? Include the member functions to perform the various operations on objects of
//type bookType.
//For example, the usual operations that can be performed on the title are to
//show the title, set the title, and check whether a title is the same as the actual
//title of the book. Similarly, the typical operations that can be performed on the
//number of copies in stock are to show the number of copies in stock, set the
//number of copies in stock, update the number of copies in stock, and return the
//number of copies in stock. Add similar operations for the publisher, ISBN, book
//price, and authors. Add the appropriate constructors and a destructor (if one is
//needed).
//? Write the definitions of the member functions of the class bookType.
//? Write a program that uses the class bookType and tests various operations on
//the objects of the class bookType. Declare an array of 100 components of type
//bookType. Some of the operations that you should perform are to search for a
//book by its title, search by ISBN, and update the number of copies of a book.
#include <iostream>
#include <string>
using namespace std;

class bookType {
private:
    string title;
    string authors[4];
    int authorCount;
    string publisher;
    string ISBN;
    double price;
    int copies;

public:
    // Default Constructor
    bookType() {
        authorCount = 0;
        price = 0.0;
        copies = 0;
    }

    // Set functions
    void setTitle(string t) {
        title = t;
    }

    void addAuthor(string a) {
        if (authorCount < 4)
            authors[authorCount++] = a;
    }

    void setPublisher(string p) {
        publisher = p;
    }

    void setISBN(string i) {
        ISBN = i;
    }

    void setPrice(double pr) {
        price = pr;
    }

    void setCopies(int c) {
        copies = c;
    }

    // Get functions
    string getTitle() {
        return title;
    }

    string getISBN() {
        return ISBN;
    }

    int getCopies() {
        return copies;
    }

    // Update copies
    void updateCopies(int c) {
        copies += c;
    }

    // Display book information
    void display() {
        cout << "Title: " << title << endl;
        cout << "Authors: ";
        for (int i = 0; i < authorCount; i++)
            cout << authors[i] << " ";
        cout << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Price: " << price << endl;
        cout << "Copies in stock: " << copies << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    bookType books[100];

    // Adding one book
    books[0].setTitle("C++ Programming");
    books[0].addAuthor("Bjarne Stroustrup");
    books[0].setPublisher("Pearson");
    books[0].setISBN("ISBN123");
    books[0].setPrice(600);
    books[0].setCopies(10);

    // Search book by title
    string searchTitle = "C++ Programming";
    for (int i = 0; i < 1; i++) {
        if (books[i].getTitle() == searchTitle) {
            books[i].display();
        }
    }

    // Search book by ISBN
    string searchISBN = "ISBN123";
    for (int i = 0; i < 1; i++) {
        if (books[i].getISBN() == searchISBN) {
            books[i].display();
        }
    }

    // Update number of copies
    books[0].updateCopies(5);

    cout << "After updating copies:" << endl;
    books[0].display();

    return 0;
}

