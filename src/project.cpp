#include "include/list.h"

int main(int argc, char *argv[]) {
    List my_list; // Create an instance of the List class
    Database data; // Create an instance of the Database class
    if(argc > 1) { // Check if a name is provided as a command line argument
        my_list.name = string(argv[1]);
        my_list.mainList = data.read_from_file();
     // Read the list from the file and return it as a vector of vectors of strin
        my_list.find_user_list();
        my_list.print_menu(); // Print the menu and handle user input
        data.write_to_file(my_list.mainList);
    }
    else {
        cout << "Please provide a name as a command line argument." << endl; 
        // Print an error message if no name is provided
    }
    
    return 0;
}