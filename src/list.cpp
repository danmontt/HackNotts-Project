#include "include/list.h"

void List::print_menu() {
    int choice;

    cout << "Please select an option from the menu below:" << endl;
    cout << "1. Print List" << endl;
    cout << "2. Add to list" << endl;
    cout << "3. Delete from list" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice and press Enter: " << endl;

    cin >> choice; // Read the user's choice

    if (choice == 1) {
        print_list();
    }
    else if (choice == 2) {
        add_to_list();
    }
    else if (choice == 3) {
        delete_from_list();
    }
    else if (choice == 4) {
        cout << "Exiting program." << endl;
        exit(0);
    }
    else {
        cout << "Invalid choice. Please try again." << endl;
        print_menu();
    }
}

void List::print_list(){
    cout << "Printing List" << endl;

    for(unsigned int list_index = 0; list_index < list.size(); list_index++){
        cout << " * " << list[list_index] << "\n";
    }

    cout << "M - Menu" << endl;
    char menu_choice;
    cin >> menu_choice;

    if (menu_choice == 'M' || menu_choice == 'm') {
        print_menu();
    }
    else {
        cout << "Invalid choice. Returning to menu." << endl;
    }
    print_menu();
}

void List::add_to_list(){
    cout << "Add Item to List" << endl;
    cout << "Enter the item to add to the list and press enter: " << endl;

    string item;
    cin >> item;

    list.push_back(item);
    cout << "Item added to the list." << endl;
    cin.clear(); // Clear the input buffer
    cin.ignore(); // Ignore the rest of the line
    print_menu();
}

void List::delete_from_list(){
    
    cout << "Delete Item from List" << endl;
    cout << "Enter the item to delete from the list and press enter: " << endl;

    if(list.size()){
        for(unsigned int i = 0; i < list.size(); i++){
            cout << i << ": " << list[i] << "\n";
        }
        int choiceNum;
        cin >> choiceNum;
        list.erase(list.begin() + choiceNum);

    }
    else{
        cout << "The list is empty." << endl;
    }
    print_menu();
}