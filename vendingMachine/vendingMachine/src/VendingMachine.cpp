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


//displays purchase, updates quantity, randomly generates items that get stuck, and recognizes when items are out of stock
void VendingMachine::makePurchase(string item){
    if(itemStuck == true){
        cout<<"Item Stuck, please go to the admin menu to open machine"<<endl;
        return;
    }
    VendingItem *node= findItem(item);
    if(node==NULL){
        return;
    }
    if(node->quantity == 0){
        cout<<node->itemName<<" is out of stock. Please enter log into the admin menu to restock."<<endl;
        return;
    }
    srand(time(0));
    int r = rand() % 10;
    if(r==5){
        nameOfItemStuck=item;
        itemStuck=true;
        cout<<"Shoot! Your item got stuck in the vending machine."<<endl;
        cout<<"go to the admin Menu to unlock the vending machine"<<endl;
        cout<<"and grab your item."<<endl;
        return;
    }
    if(itemStuck==false){
        cout<<"You bought "<<node->itemName<<" for $"<<node->price<<endl;
        revenue=revenue+node->price;
        node->quantity=node->quantity-1;
    }

}

//sets all item quantities to 5
void VendingMachine::restock(){
    if(itemStuck == true){
        cout<<"Item Stuck, please go to the admin menu to open machine"<<endl;
        return;
    }
    for(int i=0;i<4;i++){
        VendingItem *temp=hashTable[i];
        temp->quantity=5;
        while(temp->right!=NULL){
            temp=temp->right;
            temp->quantity=5;
        }
    }
    cout<<"Vending Machine Restocked"<<endl;
}

//updates new price to item passed in
void VendingMachine::changePrice(string item, int nprice){
    if(itemStuck == true){
        cout<<"Item Stuck, please go to the admin menu to open machine"<<endl;
        return;
    }
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
    if(itemStuck == true){
        cout<<"Item Stuck, please go to the admin menu to open machine"<<endl;
        return;
    }
    VendingItem *node=findItem(deleteItem);
    if(node==NULL){
        return;
    }
    node->itemName=newItem;
    node->price=newPrice;

}

//generates random index based on time and selects an item
void VendingMachine::randomItem(){
    if(itemStuck == true){
        cout<<"Item Stuck, please go to the admin menu to open machine"<<endl;
        return;
    }
    srand(time(0));
    int r = rand() % 4;
    VendingItem *temp = hashTable[r];
    if(temp->quantity == 0){
        cout<<temp->itemName<<" is out of stock. Please enter log into the admin menu to restock."<<endl;
        return;
    }
    cout<<"You bought "<<temp->itemName<<" for $"<<temp->price<<endl;
    temp->quantity = temp->quantity - 1;
    revenue=revenue+temp->price;
}

//returns the total revenue up to last withdrawal and resets the revenue to zero
int VendingMachine::revenueWithdrawal(){
    int temp = revenue;
    revenue = 0;
    return temp;
}

void VendingMachine::freeItem(){
    if(itemStuck==true){
        itemStuck=false;
        cout<<"item unstuck!"<<endl;
        makePurchase(nameOfItemStuck);
    }
    else{
        cout<<"nothing is stuck"<<endl;
    }
}

void VendingMachine::deleteVendingMachine(){
    VendingItem *temp2 = NULL;
    for(int i=0;i<4;i++){
        VendingItem *temp=hashTable[i];
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp2 = temp->left;
        while(temp != hashTable[i]){
            delete temp;
            temp = temp2;
            if(temp != hashTable[i]){
                temp2 = temp->left;
            }
        }
        delete temp;
    }
}

VendingMachine::~VendingMachine()
{
    //dtor
}
