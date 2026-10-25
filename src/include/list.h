#include <stdlib.h>
#include "database.h"
#include <iostream>
#include <vector>
using namespace std;

class List {
private:
protected:
public:
    List() {
        // Constructor
    }
    ~List() {
        // Destructor
    }
    Database data;
    vector<vector<string>> mainList;
    vector<string> list;
    string name;
    string password;
    unsigned int currentUserIndex;

    void print_menu(); // Print the menu and handle user input

    void print_list(); // Print the list to the console

    void add_to_list(); // Add an item to the list

    void delete_from_list(); // Delete an item from the list

    bool find_user_list();

    void save_list();

    int delete_whole_list();
};