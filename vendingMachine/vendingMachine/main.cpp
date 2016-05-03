#include <iostream>
#include "VendingMachine.h"
#include "Helper.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
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

    inFile.open(argv[1]);
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
        return 0;
    }

    while(userInput!=4){
        displayUserMenue();
        //read menu selection as string
        getline(cin,userI);

        //test for valid one digit int and reject if not
        //checks to see if the number is valid and if the argument is a string
        if(userI.size() == 1){
            try {
              userInput = stoi(userI,nullptr,10);
            }catch(const invalid_argument e) {
              
            }

            if(userInput != 1 and userInput != 2 and userInput != 3 and userInput !=4){
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
                    choose = 0;
                    }
                }
            else{
                cout<<"Invalid input, please try again"<<endl;
                choose = 0;
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

        //prompts user for authentication to enter vending machine settings
        else if(userInput==3){
            cout<<"In case you have not read the read me file the password is 1234"<<endl;
            cout<<"I know! its a password an idiot would put on his luggage"<<endl;
            cout<<"Enter Password"<<endl;
            string adminPassword;

            getline(cin,adminPassword);
            if(adminPassword=="1234"){
                //vm.adminCode();
                cout<<endl;
                cout<<"Welcome admin would you like to..."<<endl;
                int adminInput=0;
                string userI;
                while(adminInput!=6){
                    //print menu
                    adminMenue();

                    //read menu selection as string
                    getline(cin,userI);

                    //test for valid one digit int and reject if not
                    //checks to see if the number is valid and if the argument is a string
                    if(userI.size() == 1){
                        try{
                          adminInput = stoi(userI,nullptr,10);
                        }catch(const invalid_argument e) {

                        }

                        if(adminInput != 1 and adminInput != 2 and adminInput != 3 and adminInput !=4 and adminInput != 5 and adminInput != 6){
                            cout<<"Invalid input, please try again"<<endl;
                        }
                    }
                    else{
                        cout<<"Invalid input, please try again"<<endl;
                    }
                    //cin>>adminInput;

                    //displays the total profits since last withdrawal and sets profits back to zero
                    if(adminInput==1){
                        cout<<"You sold $"<<vm.revenueWithdrawal()<<" worth of goods"<<endl;
                    }

                    //allows user to replace an item with a new item and price within reason
                    if(adminInput==2){
                        cout<<"Enter Item to get rid of: ";
                        //string whiteSpace;
                        string deleteItem;
                        //getline(cin,whiteSpace);
                        getline(cin,deleteItem);
                        cout<<"Enter the New Item: ";
                        string newItem;
                        getline(cin,newItem);
                        cout<<"Enter the Price of the New Item ($1-$9): ";
                        string newItemPrice;
                        getline(cin,newItemPrice);

                        //checks for valid price input
                        if(newItemPrice.size()==1){
                            vm.replaceItem(deleteItem,newItem,stoi(newItemPrice,nullptr,10));
                        }
                        else{
                            cout<<"Invalid input, please try again"<<endl;
                        }
                    }

                    //Allows user to change price within reason
                    if(adminInput == 3){
                        //gather user input
                        cout<<"Enter item that you wish to change the price of: ";
                        string changeItem;
                        string price;
                        getline(cin,changeItem);
                        cout<<"Enter the new price($1-$9): ";
                        getline(cin,price);

                        //checks for valid price input
                        if(price.size()==1){
                            try{
                              vm.changePrice(changeItem, stoi(price,nullptr,10));
                            }catch(const invalid_argument e){
                              cout << "Invalid input" << endl;
                            }

                        }
                        else{
                            cout<<"Invalid input, please try again"<<endl;
                        }

                    }

                    if(adminInput == 4){
                        vm.freeItem();
                    }

                    //vending machine is restocked to capacity of 10 per item
                    if(adminInput==5){
                        vm.restock();
                    }
                    //returns to main menu
                    if(adminInput == 6){
                        cout<<"Returning to main menu..."<<endl;
                        break;
                    }
                    adminInput = 0;
                }

                adminPassword="0";
            }
            else{
                cout<<"not a valid password returning to main menu"<<endl;
            }

        }

        //exits program
        else if(userInput==4){
            cout<<"Goodbye!"<<endl;
            vm.deleteVendingMachine();
            break;
        }
        userInput = 0;
    }
    return 0;
}
