#include "/home/user/Dropbox/CSCI 2270/Project/Olsen_Link_CSCI2270_FinalProject/vendingMachine/vendingMachine/include/VendingMachine.h"
#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
using namespace std;
VendingMachine::VendingMachine()
{
    //initializing the table to NULL
    for(int i=0; i<4;i++){
        hashTable[i]=NULL;
    }
}
void VendingMachine::inserNode(string name, int index, float price){

    //adds item if no item exists at that index
    VendingItem *node = new VendingItem;
    if(hashTable[index]==NULL){
        hashTable[index]=node;
        node->itemName=name;
        node->price = price;
        node->left=NULL;
        node->right=NULL;
        node->row= index+1;
    }

    //adds item to the end of the linked list starting at the index
    else{
        VendingItem *temp=hashTable[index];
        while(temp->right!=NULL){
                temp=temp->right;
        }
        node->itemName=name;
        node->price=price;
        temp->right=node;
        node->right=NULL;
        node->left=temp;
    }


}

//Displays the currently available items in the machine and the associated quantity
void VendingMachine::displayItemsAndQuantity(){
    int count = 0;
    cout<<"                    ======Cool Vending Machine Name======"<<endl;
    cout<<"   ";
    for(int i=0;i<4;i++){
        VendingItem *temp=hashTable[i];
        cout<<hashTable[i]->itemName<<": $"<<hashTable[i]->price<<"-"<<hashTable[i]->quantity;
        count++;
        if(count % 4 == 0){
            cout<<endl;
        }
        cout<<"   ";
        while(temp->right!=NULL){
            temp=temp->right;
            cout<<temp->itemName<<": $"<<temp->price<<"-"<<temp->quantity;
            count++;
            if(count % 4 == 0){
                cout<<endl;
            }
            cout<<"   ";
        }
    }
    cout<<endl;
}

//Displays main menu
void VendingMachine::displayUserMenue(){
        cout<<endl;
        cout << "======Main Menu======" << endl;
        cout << "1. Display Items" << endl;
        cout << "2. Buy an Item" << endl;
        cout << "3. Restock" << endl;
        cout << "4. Admin Login" << endl;
        cout << "5. Quit"<<endl;
}

//finds item and returns pointer to that item
VendingItem *VendingMachine::findItem(string item){
    for(int i=0;i<4;i++){
        VendingItem *temp=hashTable[i];
        if(temp->itemName==item){
            return temp;
        }
        while(temp->right!=NULL){
            temp=temp->right;
            if(temp->itemName==item){
                return temp;
            }
        }
    }
    cout<<"Item does not exist!"<<endl;
    return NULL;
}

//displays purchase and updates quantity
void VendingMachine::makePurchase(string item){
    VendingItem *node= findItem(item);
    if(node==NULL){
        return;
    }
    else{
        cout<<"You bought "<<node->itemName<<" for $"<<node->price<<endl;
        revenue=revenue+node->price;
        node->quantity=node->quantity-1;
    }
}

//sets all item quantities to 10
void VendingMachine::restock(){
    for(int i=0;i<4;i++){
        VendingItem *temp=hashTable[i];
        temp->quantity=10;
        while(temp->right!=NULL){
            temp=temp->right;
            temp->quantity=10;
        }
    }
}

//displays administrator menu
void VendingMachine::adminMenue(){
    cout<<endl;
    cout<<"1. Withdraw Money and Display Revenue"<<endl;
    cout<<"2. Replace an item"<<endl;
    cout<<"3. Change the Price of an item"<<endl;
    cout<<"4. Return to Public Menu"<<endl;
}

//updates new price to item passed in
void VendingMachine::changePrice(string item, int nprice){
    VendingItem *node= findItem(item);
    if(node != NULL && nprice > 0 && nprice <= 100){
        node->price = nprice;
    }
    else{
        cout<<"item not found"<<endl;
    }
}

//deletes old item name and prices and replaces them with new passed in values
void VendingMachine::replaceItem(string deleteItem, string newItem,int newPrice){
    VendingItem *node=findItem(deleteItem);
    if(node==NULL){
        return;
    }
    node->itemName=newItem;
    node->price=newPrice;

}

//selection for admin options
void VendingMachine::adminCode(){
    cout<<endl;
    cout<<"Welcome admin would you like to..."<<endl;
    int adminInput=0;
    string userI;
    while(adminInput!=4){
        //print menu
        adminMenue();

        //read menu selection as string
        getline(cin,userI);

        //test for valid one digit int and reject if not
        //checks to see if the number is valid and if the argument is a string
        if(userI.size() == 1){
            adminInput = stoi(userI,nullptr,10);
            if(adminInput != 1 and adminInput != 2 and adminInput != 3 and adminInput !=4){
                cout<<"Invalid input, please try again"<<endl;
            }
        }
        else{
            cout<<"Invalid input, please try again"<<endl;
        }
        //cin>>adminInput;

        //displays the total profits since last withdrawal and sets profits back to zero
        if(adminInput==1){
            cout<<"You sold $"<<revenue<<" worth of goods"<<endl;
            revenue=0;
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
                replaceItem(deleteItem,newItem,stoi(newItemPrice,nullptr,10));
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
                changePrice(changeItem, stoi(price,nullptr,10));
            }
            else{
                cout<<"Invalid input, please try again"<<endl;
            }

        }

        //returns to main menu
        if(adminInput == 4){
            cout<<"Returning to main menu..."<<endl;
            return;
        }
        adminInput = 0;
    }

}

//generates random index based on time and selects an item
void VendingMachine::randomItem(){
    srand(time(0));
    int r = rand() % 4;
    VendingItem *temp = hashTable[r];
    cout<<"You bought "<<temp->itemName<<" for $"<<temp->price<<endl;
    temp->quantity = temp->quantity - 1;
    revenue=revenue+temp->price;
}

VendingMachine::~VendingMachine()
{
    //dtor
}
