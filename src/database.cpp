#include "include/database.h"

void Database::write_to_file(vector<vector<string>> mainList) {
    ofstream db;
    db.open("db/list.sl");

    if (db.is_open()) {
        for (unsigned int user_index = 0; user_index < mainList.size(); user_index++) {
            for(unsigned int list_index = 0; list_index < mainList[user_index].size(); list_index++){
                if (list_index == 0){
                    db << "#" << mainList[user_index][list_index] << '\n';
                }
                else{
                    db << mainList[user_index][list_index] << '\n';
                }
            }
            db << "%" << "\n";
        }
    }
    else {
        cout << "Error opening file for writing.\n";
    }
    
    db.close();
}

vector<vector<string>> Database::read_from_file() {
    string line;
    ifstream db;
    db.open("db/list.sl");

    vector<string> userList; // Create a vector to store the list items

    if (db.is_open()) {
        while (getline(db, line, '\n')) { // Read each line from the file
            if (line.front() == '#') { // Check if the line is not empty
                cout << "Found a hashtag: " << line << "\n"; // Print the line to the console
                line.erase(line.begin());
                userList.push_back(line); // Add the line to the list
            }
            else if (line.front() == '%') { // Check if the line is not empty
                cout << "Found a percentage: " << line << "\n"; // Print the line to the console
                mainList.push_back(userList);
                userList.clear();
            }
            else {
                cout << "Found an item: " << line << "\n";
                userList.push_back(line); // Add the line to the list
            }
        }
    }
    else {
        cout << "Error opening file for writing.\n";
    }
    
    db.close();
    return mainList;
}