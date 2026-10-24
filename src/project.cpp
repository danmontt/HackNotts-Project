#include "include/list.h"
#include "include/database.h"

int main(int argc, char *argv[]) {
    List my_list; // Create an instance of the List class
    Database data; // Create an instance of the Database class
    if(argc > 1) { // Check if a name is provided as a command line argument
        my_list.name = string(argv[1]);
        my_list.print_menu();
        data.write_to_file(my_list.list); // Write the list to the file
        data.read_from_file();
    }
    else {
        cout << "Please provide a name as a command line argument." << endl;
    }
    
    return 0;
}