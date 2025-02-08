#include <iostream>
#include <vector>

using namespace std;

struct Book{
    string Id;
    string title;
    string genre;
    string author;
    string category;
    int number_of_copies;
    int number_of_borrowed;

    Book *next;
};

class Library {
private:
    static Book *Book_head; //POINT TO THE FIRST ELEMENT IN THE BOOK LIST
public:
    Library();
    static void Add_new_book();
    static void Add_copy();
    static bool SearchID(const string&);

    static void Search_by_id();
    static void Search_by_title();
    static void Search_by_author();
    static void Show_all_books();
    static void Display(Book*);
    static bool Is_Empty();
    static bool Is_Full();

    static void Delete_book();

    static void Borrow();
    static void Return_book();

    static int count();
};
