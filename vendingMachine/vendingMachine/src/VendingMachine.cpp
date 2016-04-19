#include "/home/user/Dropbox/CSCI 2270/Project/Olsen_Link_CSCI2270_FinalProject/vendingMachine/vendingMachine/include/VendingMachine.h"
#include <iostream>
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


VendingMachine::~VendingMachine()
{
    //dtor
}
