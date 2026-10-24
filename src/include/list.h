#include <stdlib.h>
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
    vector<string> list;
    string name;

    void print_menu();

    void print_list();

    void add_to_list();

    void delete_from_list();
};