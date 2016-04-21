#include <iostream>
#include "/home/user/Dropbox/Computer Science/assignments/project2/Olsen_Link_CSCI2270_FinalProject/vendingMachine/vendingMachine/include/VendingMachine.h"
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
    while(userInput!=5){
        if(userInput==1){
            vm.displayItemsAndQuantity();
        }
        if(userInput==2){
            cout<<"Enter Item Name: ";
            string whiteSpace;
            string itemWanted;
            getline(cin,whiteSpace);
            getline(cin,itemWanted);
            vm.makePurchase(itemWanted);
        }
        if(userInput==3){
            vm.restock();
        }
        if(userInput==4){
            cout<<"In case you have not read the read me file the password is 1234"<<endl;
            cout<<"I know! its a password an idiot would put on his luggage"<<endl;
            cout<<"Enter Password"<<endl;
            string adminPassword;
            string whiteSpace;
            getline(cin,whiteSpace);
            getline(cin,adminPassword);
            if(adminPassword=="1234"){
                vm.adminCode();
                adminPassword="0";
            }
            else{
                cout<<"not a valid password returning to main menu"<<endl;
            }

        }
        vm.displayUserMenue();
        cin>>userInput;
        if(userInput==5){
            cout<<"Goodbye!"<<endl;
        }
    }
    return 0;
}
