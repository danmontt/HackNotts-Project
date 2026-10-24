#include "include/list.h"

void List::print_menu() {
    int choice;

    cout << "Please select an option from the menu below:" << endl;
    cout << "1. Print List" << endl;
    cout << "2. Add to list" << endl;
    cout << "3. Delete from list" << endl;
    cout << "4. Save Database" << endl;
    cout << "5. Exit" << endl;
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
        save_list(); // Exit the menu
    }
    else if (choice == 5) {
        return; // Exit the menu
    }
    else {
        cout << "Invalid choice. Please try again." << endl;
        print_menu();
    }
}


void List::add_to_list() {

    cout << "\n\n\n\n\n\n\n\n";
    cout << "*** Add Item ***\n";
    cout << "Type in an item and press enter: ";

    string item;
    cin >> item;

    list.push_back(item);

    cout << "Successfully added an item to the list \n\n\n\n\n";
    cin.clear();

    print_menu();

}

void List::delete_from_list() {

    cout << "*** Delete Item ***\n";
    cout << "Select an item index number to delete: \n";

    if(list.size()) {
        for(unsigned int i=0; i < list.size(); i++){
            cout << i << ": " << list[i] << "\n";
        }
        int choiceNum;
        cin >> choiceNum;
        list.erase(list.begin()+choiceNum);
    }    
    else {
        cout << "No items in the list or to delete.\n";
    }

    print_menu();

}

void List::print_list() {

    cout << "*** Printing List ***\n";

    for(unsigned int list_index=0; list_index < list.size(); list_index++) {
        cout << " * " << list[list_index] << "\n";
    }

    cout << "M - Menu \n";
    char choice;
    cin >> choice;

    if(choice == 'M' || choice == 'm') {
        print_menu();
    }
    else {
        cout << "Invalid Choice. Quitting..\n";
    }

}

bool List::find_user_list(){ // Print the list to the console
    bool userFound = false;
    std::cout << R"(
                       _.-**-._
                    _,(        ),_
                 .-"   '-^----'   "-.
              .-'                    '-.
            .'                          '.
          .'    __.--**'""""""'**--.__    '.
         /_.-*"'__.--**'""""""'**--.__'"*-._\
        /_..-*"'   .-*"*-.  .-*"*-.   '"*-.._\
       :          /       ;:       \          ;
       :         :     *  !!  *     :         ;
        \        '.     .'  '.     .'        /
         \         '-.-'      '-.-'         /
      .-*''.                              .'-.
   .-'      '.                          .'    '.
  :           '-.        _.._        .-'        '._
 ;"*-._          '-._  --___ `   _.-'        _.*'  '*.
:      '.            `"*-.__.-*"`           (        :
 ;      ;                 *|                 '-.     ;
  '---*'                   |                    ""--'
   :                      *|                      :
   '.                      |                     .'
     '.._                 *|        ____----.._-'
      \  """----_____------'-----"""         /
       \  __..-------.._        ___..---._  /
       :'"              '-..--''          "';
        '""""""""""""""""' '"""""""""""""""'

)" << '\n';
    cout << "*** Welcome " << name << "***\n";

    for (unsigned int user_index = 0; user_index < mainList.size(); user_index++){
        cout << mainList[user_index][0] << '\n';
        if (mainList[user_index][0] == name){
            cout << "User has been found: " << mainList[user_index][0] << "\n";
            list = mainList[user_index];
            currentUserIndex = user_index;
            userFound = true;
            break;
        }
    }
    if (userFound == false){
        list.push_back(name);
        mainList.push_back(list);
        currentUserIndex = mainList.size()-1;
    }

    return userFound;
}

void List::save_list(){
    cout << "Saving the List...\n";
    mainList[currentUserIndex] = list;
    print_menu();
}