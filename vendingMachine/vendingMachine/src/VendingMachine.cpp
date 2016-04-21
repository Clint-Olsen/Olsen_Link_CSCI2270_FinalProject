#include "/home/user/Dropbox/Computer Science/assignments/project2/Olsen_Link_CSCI2270_FinalProject/vendingMachine/vendingMachine/include/VendingMachine.h"
#include <iostream>
#include <string>
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
        //cout<<node->itemName<<endl;
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
        //cout<<node->itemName<<endl;
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

void VendingMachine::displayUserMenue(){
        cout << "======Main Menu======" << endl;
        cout << "1. Display Items" << endl;
        cout << "2. Buy an Item" << endl;
        cout << "3. Restock" << endl;
        cout << "4. Admin Login" << endl;
        cout << "5. Quit"<<endl;
}
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
void VendingMachine::makePurchase(string item){
    VendingItem *node= findItem(item);
    if(node==NULL){
        return;
    }
    else{
        revenue=revenue+node->price;
        node->quantity=node->quantity-1;
    }
}
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
void VendingMachine::adminMenue(){
    cout<<"1. Withdraw Money and Display Revenue"<<endl;
    cout<<"2. Replace an item"<<endl;
    cout<<"3. Change the Price of an item"<<endl;
    cout<<"4. Return to Public Menu"<<endl;
}
void VendingMachine::replaceItem(string deleteItem, string newItem,int newPrice){
    VendingItem *node=findItem(deleteItem);
    if(node==NULL){
        return;
    }
    node->itemName=newItem;
    node->price=newPrice;

}
void VendingMachine::adminCode(){
    cout<<"Welcome admin would you like to..."<<endl;
    int adminInput=0;
    while(adminInput!=4){
        adminMenue();
        cin>>adminInput;
        if(adminInput==1){
            cout<<"You sold "<<revenue<<"$ worth of goods"<<endl;
            revenue=0;
        }
        if(adminInput==2){
            cout<<"Enter Item to get rid of: ";
            string whiteSpace;
            string deleteItem;
            getline(cin,whiteSpace);
            getline(cin,deleteItem);
            cout<<"Enter the New Item: ";
            string newItem;
            getline(cin,newItem);
            cout<<"Enter the Price of the New Item: ";
            string newItemPrice;
            getline(cin,newItemPrice);
            replaceItem(deleteItem,newItem,stoi(newItemPrice,nullptr,10));
        }
    }

}

VendingMachine::~VendingMachine()
{
    //dtor
}
