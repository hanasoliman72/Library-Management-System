#include <iostream>
#include <limits>
#include "Library.h"

using namespace std;

Book* Library::Book_head = nullptr; //DEFINE STATIC MEMBER

Library::Library() = default;

void Library::Add_new_book() {
    //CHECK IF THE MEMORY IS FULL
    if(Is_Full()) {
        cout << "Memory is full\n";
        return;
    }

    //CREATE NEW NODE
    Book *new_node = new Book;

    //INPUT DETAILS
    cout << "Enter Book id:  ";
    cin >> new_node->Id;
    cout << "\n";
    //SEARCH IF THIS ID IS ALREADY EXIST
    if(SearchID(new_node->Id)) {
        cout << "This ID is already exist\n";
        delete new_node;
        return;
    }

    cout << "Enter Book title:  ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // IGNORE LEFTOVER NEWLINE
    getline(cin, new_node->title);
    cout << "\n";

    cout << "Book category: Enter 1 for Fiction and 2 for Non-Fiction:  ";
    int choice;
    //CHECK IF THE USER ENTER A CHAR OR A STRING
    while(!(cin >> choice)) {
        cout << "INVALID INPUT, Please enter a number.\n";
        //CLEAR THE PREVIOUS INPUT
        cin.clear();
        //DISCARD PREVIOUS INPUT
        cin.ignore(123,'\n');
    }

    if(choice == 1) {
        new_node->category = "Fiction";
        cout << "Enter Book genre:  ";
        cout << "1.Fantasy   2.Romance   3.Crime   4.Science fiction ";
        int option;
        //CHECK IF THE USER ENTER A CHAR OR A STRING
        while(!(cin >> option)) {
            cout << "INVALID INPUT, Please enter a number.\n";
            //CLEAR THE PREVIOUS INPUT
            cin.clear();
            //DISCARD PREVIOUS INPUT
            cin.ignore(123,'\n');
        }

        if(option == 1) new_node->genre = "Fantasy";
        else if(option == 2) new_node->genre = "Romance";
        else if(option == 3) new_node->genre = "Crime";
        else if(option == 4) new_node->genre = "Science fiction";
        else {
            cout << "INVALID INPUT, Please enter a number between 1 and 4\n";
            return;
        }
    }
    else if(choice == 2) {
        new_node->category = "Non-Fiction";
        cout << "Enter Book genre:  ";
            cout << "1.History   2.Science   3.Philosophy   4.Language:  ";
        int option;
        //CHECK IF THE USER ENTER A CHAR OR A STRING
        while(!(cin >> option)) {
            cout << "INVALID INPUT, Please enter a number.\n";
            //CLEAR THE PREVIOUS INPUT
            cin.clear();
            //DISCARD PREVIOUS INPUT
            cin.ignore(123,'\n');
        }

        if(option == 1) new_node->genre = "History";
        else if(option == 2) new_node->genre = "Science";
        else if(option == 3) new_node->genre = "Philosophy";
        else if(option == 4) new_node->genre = "Language";
        else {
            cout << "INVALID INPUT, Please enter a number between 1 and 4\n";
            delete new_node;
            return;
        }
    }
    else {
        cout << "INVALID INPUT, Please enter a number between 1 and 2\n";
        delete new_node;
        return;
    }

    cout << "Enter book author name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //IGNORE LEFTOVER NEWLINE
    getline(cin, new_node->author);
    cout << "\n";

    //NUMBER OF COPIES INITIALLY ZERO
    new_node->number_of_copies = 0;

    //NUMBER OF BORROWED BOOKS INITIALLY ZERO
    new_node->number_of_borrowed = 0;


    //INSERT NEW NODE
    if(Book_head == nullptr) { //FIRST NODE
        Book_head = new_node;
        new_node->next = nullptr;
    }
    else { //IS NOT FIRST NODE
        Book *last;
        last = Book_head;
        while(last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = nullptr;
    }
}


void Library::Add_copy() {
    string id;
    cout << "Enter Book id:  ";
    cin >> id;
    cout << "\n";
    //SEARCH IF THIS ID ISN'T EXIST
    if(!SearchID(id)) {
        cout << "This id doesn't exist\n";
        return;
    }

    Book *current = Book_head;
    while(current != nullptr) {
        if(current->Id == id) {
            current->number_of_copies++;
            cout << "Copy added successfully\n";
            return;
        }
        current = current->next;
    }

}

bool Library::SearchID(const string& id) {
    Book *current = Book_head;
    while(current != nullptr) {
        if(current->Id == id) return true;
        current = current->next;
    }
    return false;
}


void Library::Search_by_id(){
    //CHECK IF THERE IS NO RECORDED BOOK
    if(Is_Empty()) {
        cout << "There is no recorded books\n";
        return;
    }

    string id;
    cout << "Enter Book id: ";
    cin >> id;
    cout << "\n";


    Book *current = Book_head;
    while(current != nullptr) {
        if(current->Id == id) {
            Display(current);
            return;
        }
        current = current->next;
    }
    cout << "Not Found\n";
}


void Library::Search_by_title() {
    //CHECK IF THERE IS NO RECORDED BOOK
    if(Is_Empty()) {
        cout << "There is no recorded books\n";
        return;
    }

    string title;
    cout << "Enter Book title:  ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // IGNORE LEFTOVER NEWLINE
    getline(cin, title);
    cout << "\n";

    Book *current = Book_head;
    bool found = false;
    while(current != nullptr) {
        if(current->title == title) {
            Display(current);
            found = true;
        }
        current = current->next;
    }

    if(!found) cout << "Not Found\n";
}


void Library::Search_by_author() {
    //CHECK IF THERE IS NO RECORDED BOOK
    if(Is_Empty()) {
        cout << "There is no recorded books\n";
        return;
    }

    string author;
    cout << "Enter book author name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //IGNORE LEFTOVER NEWLINE
    getline(cin, author);
    cout << "\n";

    Book *current = Book_head;
    bool found = false;
    while(current != nullptr) {
        if(current->author == author) {
            Display(current);
            found = true;
        }
        current = current->next;
    }

    if(!found) cout << "Not Found\n";
}


void Library::Show_all_books() {
    //CHECK IF THERE IS NO RECORDED BOOK
    if(Is_Empty()) {
        cout << "There is no recorded books\n";
        return;
    }

    Book *current = Book_head;
    while(current != nullptr) {
        Display(current);
        current = current->next;
    }
}


void Library::Display(Book *ptr) {
    cout << "Book id: " << ptr->Id << "\n";
    cout << "Book title: " << ptr->title << "\n";
    cout << "Book category: " << ptr->category << "\n";
    cout << "Book genre: " << ptr->genre << "\n";
    cout << "Book author name: " << ptr->author << "\n";
    cout << "Number of copies: " << ptr->number_of_copies << "\n";
    cout << "Number of borrowed books: " << ptr->number_of_borrowed << "\n\n";
}


bool Library::Is_Empty() {
    return (Book_head == nullptr);
}


bool Library::Is_Full() {
    Book *temp;

    //TRY TO CREATE NEW NODE, IF IT WORK THEN RETURN FALSE
    //OTHERWISE RETURN TRUE
    try {
        temp = new Book;
        delete(temp);
        return false;
    }
    catch(bad_alloc &exception) {
        return true;
    }
}


void Library::Delete_book() {
    //CHECK IF THERE IS NO RECORDED BOOK
    if(Is_Empty()) {
        cout << "There is no recorded books\n";
        return;
    }

    string id;
    cout << "Enter Book id: ";
    cin >> id;
    cout << "\n";
    //SEARCH IF THIS ID ISN'T EXIST
    if(!SearchID(id)) {
        cout << "This id doesn't exist\n";
        return;
    }

    Book *current,*previous;
    current  = Book_head;
    previous = Book_head;
    if(current->Id == id) {//IF THE DELETED NODE IS THE FIRST NODE
        Book_head = current->next;
        delete(current);//DELETE NODE FROM MEMORY
        cout << "Book deleted successfully\n";
        return;
    }

    //IF THE DELETED NODE IS NOT THE FIRST NODE
    //WE SEARCH UNTIL FIND OUR NODE
    while(current->Id != id) {
        previous = current;
        current = current->next;
    }
    //MAKE THE PREVIOUS OF OUR NODE POINT TO THE NEXT OF IT
    previous->next = current->next;
    delete(current);//DELETE NODE FROM MEMORY

    cout << "Book deleted successfully\n";
}


void Library::Borrow() {
    //CHECK IF THERE IS NO RECORDED BOOK
    if(Is_Empty()) {
        cout << "There is no recorded books\n";
        return;
    }

    string id;
    cout << "Enter book id: ";
    cin >> id;
    //SEARCH IF THIS ID ISN'T EXIST
    if(!SearchID(id)) {
        cout << "This id doesn't exist\n";
        return;
    }


    //DECREASE NUMBER OF COPIES BY ONE
    Book *current = Book_head;
    while(current != nullptr) {
        if(current->Id == id && current->number_of_copies > 0) {
            current->number_of_copies--;
            current->number_of_borrowed++;
            cout << "Book borrowed successfully\n";
            return;
        }
        current = current->next;
    }

    cout << "There is no copies of this book to borrow\n";
}


void Library::Return_book() {
    string id;
    cout << "Enter book id: ";
    cin >> id;
    //SEARCH IF THIS ID ISN'T EXIST
    if(!SearchID(id)) {
        cout << "This id doesn't exist\n";
        return;
    }


    //INCREASE NUMBER OF COPIES BY ONE
    Book *current = Book_head;
    while(current != nullptr) {
        if(current->Id == id) {
            //CHECK IF NO COPY BORROWED
            if(current->number_of_borrowed == 0) {
                cout << "This copy wasn't borrowed\n";
                return;
            }
            //OTHERWISE INCREASE NUMBER OF COPIES
            //DECREASE NUMBER OF BORROWED BOOKS
            current->number_of_copies++;
            current->number_of_borrowed--;
            cout << "Book returned successfully\n";
            return;
        }
        current = current->next;
    }

}


int Library::count() {
    //CREATE A POINTER TO BOOK
    Book *current = Book_head;

    int counter = 0;
    while(current != nullptr) {
        //NUMBER OF ALL BOOKS = NUMBER OF COPIES BOOKS + NUMBER OF BORROWED BOOKS
        counter += current->number_of_copies + current->number_of_borrowed;
        current = current->next;
    }
    return counter;
}




