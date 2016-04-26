#include "Helper.h"
#include <iostream>

using namespace std;

//Displays main menu
void displayUserMenue(){
        cout<<endl;
        cout << "======Main Menu======" << endl;
        cout << "1. Display Items" << endl;
        cout << "2. Buy an Item" << endl;
        cout << "3. Admin Login" << endl;
        cout << "4. Quit"<<endl;
}

//displays administrator menu
void adminMenue(){
    cout<<endl;
    cout<<"1. Withdraw Money and Display Revenue"<<endl;
    cout<<"2. Replace an item"<<endl;
    cout<<"3. Change the Price of an item"<<endl;
    cout<<"4. Free Stuck Item"<<endl;
    cout<<"5. Restock"<<endl;
    cout<<"6. Return to Public Menu"<<endl;
}
