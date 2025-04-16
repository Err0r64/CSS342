//
// Created by Alec Situ on 4/15/25.
/*
 * Notes for Pop quiz
 */
#include <iostream>
#include <sstream>
class Book {
  /*
   * Private Variables
   *     Name of the book, genre, author, publisher, date of publication.
   */
    private:
        std::string author;
        std::string title;
        int published_date;
        int id = 0; // Default value of zero means the book is the original copy.


  public:

    Book() : author(""), title(""), published_date(0), id(0) {}

    // Can I create a constructor that defaults the ID to 0 if it's the original copy?
    Book(std::string author, std::string title, int published_date, int id) { // Building the constructor
        this->author = author;
        this->title = title;
        this->published_date = published_date;
        this->id = id++;
    }

    int getPublishedDate() {
        return published_date;
    }

    int getId() {
        return id;
    }

    std::string getAuthor() {
        return author;
    }

    std::string getTitle() {
        return title;
    }

    void setID(int id) {
        this->id = id;
    }

    std::string toString() {
        std::ostringstream oss;
        oss << "Title: " << title << "\n"
            << "Author: " << author << "\n"
            << "Published Date: " << published_date << "\n"
            << "ID: " << id << "\n";

        return oss.str();
    }

};

Book copy_a_book(Book originalBook) {
    Book *copy = new Book(originalBook.getAuthor(), originalBook.getTitle(), originalBook.getPublishedDate(),
                     originalBook.getId() + 1); // This area is still not incrementing the ID on copy.
    return *copy;
}

Book* copy_books(const Book& originalBook, int n) {
    if (n<=0) {
        return nullptr;
    }
    Book *books = new Book[n];

    Book currentBook = copy_a_book(originalBook);
    for (int i = 0; i < n; i++) {
        // Copy the book
        books[i] = copy_a_book(currentBook);
        currentBook = books[i];
    }

    return books;


}


/*
 * Before next lecture you want to makes sure this is functional
 *  You want to make sure ID increments everytime you copy the book.
 */
int main() {
    // We want to manage some books.
    std::cout << "<<< PRINTING RESULTS FROM FIRST BOOK >>> " << std::endl;
    Book *book = new Book("Alec", "Rock, Paper, Scissors", 2004, 1);
    std::cout << book->toString() << std::endl;
    std::cout << " +==================================+ " << std::endl;

    std::cout << "<<< PRINTING THE THE COPY >>>" << std::endl;
    Book book_copy = copy_a_book(*book);
    std::cout << book_copy.toString() << std::endl;
    std::cout << " +==================================+ " << std::endl;

    std::cout << "<<< COPYING BOOKS INTO ARRAY >>>" << std::endl;
    Book* copies = copy_books(book_copy, 2);
    std::cout << "<<< PRINTING THE ARRAY OF COPIES >>>" << std::endl;
    for (int i = 0; i < 2; i++) {
        std::cout << "Copies: " << copies[i].toString() << std::endl;
    }

    delete[] copies;
    delete book;
}

