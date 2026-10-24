#include "include/database.h"

void Database::write_to_file(vector<string> list) {
    ofstream db;
    db.open("db/list.sl");

    if (db.is_open()) {
        for (unsigned int list_index = 0; list_index < list.size(); list_index++) {
            db << list[list_index] << '\n'; // Write each item to the file
        }
    }
    else {
        cout << "Error opening file for writing.\n";
    }
    
    db.close();
}

void Database::read_from_file() {
    string line;
    ifstream db;
    db.open("db/list.sl");

    if (db.is_open()) {
        while (getline(db, line, '\n')) { // Read each line from the file
            cout << line << '\n'; // Print the line to the console
        }
    }
    else {
        cout << "Error opening file for writing.\n";
    }
    
    db.close();
}