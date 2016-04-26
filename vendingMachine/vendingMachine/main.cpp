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
    int choose = 0;
    float price1;
    int userInput=0;
    string userI;

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

    while(userInput!=5){
        vm.displayUserMenue();
        //read menu selection as string
        getline(cin,userI);

        //test for valid one digit int and reject if not
        //checks to see if the number is valid and if the argument is a string
        if(userI.size() == 1){
            userInput = stoi(userI,nullptr,10);
            if(userInput != 1 and userInput != 2 and userInput != 3 and userInput !=4 and userInput != 5){
                cout<<"Invalid input, please try again"<<endl;
            }
        }
        else{
            cout<<"Invalid input, please try again"<<endl;
        }

        //display items within the machine, quantity and prices
        if(userInput==1){
            vm.displayItemsAndQuantity();
        }

        // selection option from the vending machine
        else if(userInput==2){
            //submenu
            cout<<"Would you like to..."<<endl;
            cout<<"1. Choose an item"<<endl;
            cout<<"2. Surprise me"<<endl;

            //gather input from user for option
            getline(cin,userI);

            //test for valid one digit int and reject if not
            //checks to see if the number is valid and if the argument is a string based on size
            if(userI.size() == 1){
                choose = stoi(userI,nullptr,10);
                if(choose != 1 and choose != 2){
                    cout<<"Invalid input, please try again"<<endl;
                    }
                }
            else{
                cout<<"Invalid input, please try again"<<endl;
            }

            //user manually enters item name
            if(choose == 1){
                cout<<"Enter Item Name: ";
                string itemWanted;
                getline(cin,itemWanted);
                vm.makePurchase(itemWanted);
            }

            //random item is generated
            else if(choose == 2){
                vm.randomItem();
            }

        }

        //vending machine is restocked to capacity of 10 per item
        else if(userInput==3){
            vm.restock();
        }

        //prompts user for authentication to enter vending machine settings
        else if(userInput==4){
            cout<<"In case you have not read the read me file the password is 1234"<<endl;
            cout<<"I know! its a password an idiot would put on his luggage"<<endl;
            cout<<"Enter Password"<<endl;
            string adminPassword;

            getline(cin,adminPassword);
            if(adminPassword=="1234"){
                vm.adminCode();
                adminPassword="0";
            }
            else{
                cout<<"not a valid password returning to main menu"<<endl;
            }

        }

        //exits program
        else if(userInput==5){
            cout<<"Goodbye!"<<endl;
            break;
        }
        userInput = 0;
    }
    return 0;
}

