#include <iostream>
#include "/home/user/Dropbox/CSCI 2270/Project/Olsen_Link_CSCI2270_FinalProject/vendingMachine/vendingMachine/include/VendingMachine.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    VendingMachine vm;
    ifstream inFile;
    string line;
    string row1;
    string name;
    string price;
    float price1;
    inFile.open("vendingItems.txt");
    if(inFile.good()){
        int index=0;

        //this while loop reads in all the vending items/prices and stores them into a hash table
        while (getline(inFile,line)){
            row1=line;
            stringstream ss(row1);
            //get item name
            getline(ss,name,',');
            //get price
            getline(ss,price,',');
            price1 = stof(price,nullptr);
            vm.inserNode(name,index,price1);

            //get item name
            getline(ss,name,',');
            //get price
            getline(ss,price,',');
            price1 = stof(price,nullptr);
            vm.inserNode(name,index,price1);

            //get item name
            getline(ss,name,',');
            //get price
            getline(ss,price,',');
            price1 = stof(price,nullptr);
            vm.inserNode(name,index,price1);

            //get item name
            getline(ss,name,',');
            //get price
            getline(ss,price,',');
            price1 = stof(price,nullptr);
            vm.inserNode(name,index,price1);

            index=index+1;

        }
    }
    else{
        cout<<"File did not open"<<endl;
    }
    int userInput=0;
    while(userInput!=4){
        if(userInput==1){
            vm.displayItemsAndQuantity();
        }
        if(userInput==2){

        }
        if(userInput==3){

        }
        cout << "======Main Menu======" << endl;
        cout << "1. Display Items" << endl;
        cout << "2. Buy an Item" << endl;
        cout << "3. Restock" << endl;
        cout << "4. Quit" << endl;
        cin>>userInput;
        if(userInput==4){
            cout<<"Goodbye!"<<endl;
        }
    }
    return 0;
}
