#include "include/list.h"

int main(int argc, char *argv[]) {
    if(argc > 1) { // Check if a name is provided as a command line argument
        List my_list; // Create an instance of the List class
        my_list.name = string(argv[1]);
        my_list.print_menu();
    }
    else {
        cout << "Please provide a name as a command line argument." << endl;
    }
    return 0;
}