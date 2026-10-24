#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Database {
private:
protected:
public:
    Database() {
        // Constructor
    }
    ~Database() {
        // Destructor
    }
    vector<vector<string>> mainList;
    string name;

    void write_to_file(vector<vector<string>> mainList); // Write the list to the file
    vector<vector<string>> read_from_file(); // Read the list from the file and return it as a vector of vectors of strings
};