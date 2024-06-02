#include <iostream>
#include "Library.h"

using namespace std;

int main() {

    cout << "-----------------------------------------Welcome to our world:)-----------------------------------------\n\n";

    int choice;
    do {

        cout << "---------------------------------------------------------------------------------\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "Please choose one of this functions to operate:\n\n";

        cout << "1.Add New book\n";
        cout << "2.Add a copy\n";
        cout << "3.Search for book by ID\n";
        cout << "4.Delete book by ID\n";
        cout << "5.Show books\n";
        cout << "6.Search for book by title\n";
        cout << "7.Search for book by author name\n";
        cout << "8.Borrow\n";
        cout << "9.Return book\n";
        cout << "10.number of Books\n";
        cout << "11.Exit\n";
        cout << "---------------------------------------------------------------------------------\n";
        cout << "---------------------------------------------------------------------------------\n";

        //USER INPUT
        //CHECK IF THE USER ENTER A CHAR OR A STRING
        while(!(cin >> choice)) {
            cout << "INVALID INPUT, Please enter a number.\n";
            //CLEAR THE PREVIOUS INPUT
            cin.clear();
            //DISCARD PREVIOUS INPUT
            cin.ignore(123,'\n');
        }

        //ADD NEW BOOK
        if(choice == 1) Library::Add_new_book();

        //ADD COPY
        else if(choice == 2) Library::Add_copy();

        //SEARCH FOR BOOK BY ID
        else if(choice == 3) Library::Search_by_id();

        //DELETE BOOK BY ID
        else if(choice == 4) Library::Delete_book();

        //SHOW ALL BOOKS
        else if(choice == 5) Library::Show_all_books();

        //SEARCH FOR BOOK BY TITLE
        else if(choice == 6) Library::Search_by_title();

        //SEARCH FOR BOOK BY AUTHOR
        else if(choice == 7) Library::Search_by_author();

        //BORROW BOOK
        else if(choice == 8) Library::Borrow();

        //RETURN BORROWED BOOK
        else if(choice == 9) Library::Return_book();

        //COUNT NUMBER OF BOOKS
        if(choice == 10) cout << Library::count() << "\n";

        else if(choice != 11){
            cout << "INVALID INPUT, Please enter a number between 1 and 10\n";
        }

    } while(choice != 11);
    cout << "-----------------------------------------See you soon:)-----------------------------------------\n";
    return 0;
}
