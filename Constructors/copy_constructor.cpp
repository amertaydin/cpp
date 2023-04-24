#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    float *rates;
    int ratesCounter;

    Book(string title, string author) {
        this->title = title;
        this->author = author;

        ratesCounter = 2;
        rates = new float[ratesCounter];
        rates[0] = 5;
        rates[1] = 4;
    }

    ~Book() {
        delete []rates;
        rates = nullptr;
    }

    // Copy construtor receieves one parameter with parameter type is same as Class, passed as reference
    // By writing const, we protect original object from modification
    Book(const Book& original) {
        this->title = original.title;
        this->author = original.author;
        this->ratesCounter = original.ratesCounter;

        this->rates = new float[ratesCounter];
        for (int i = 0; i < ratesCounter; i++) {
            rates[i] = original.rates[i];
        }
    }
};

void PrintBook(Book book) {
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;

    float sum = 0;
    for (int i = 0; i < book.ratesCounter; i++) {
            sum += book.rates[i];
    }

    cout << "Average Rate: " << sum/book.ratesCounter << endl;
}

int main() {
    Book book1("Millionaire Fastlane", "M. J. DeMarco");
    Book book2("C++ Lambda Story", "Bartek F.");

    // Whenever a NEW object is created based on an existing object, copy constructor is invoked

    // Book book3(book1);
    Book book3 = book1; // They are the same
    
    // When you are passing an object to a function by value
    PrintBook(book1);
    PrintBook(book2);
    PrintBook(book3);

    // When you are returning an object from a function by value

    cin.get();
}