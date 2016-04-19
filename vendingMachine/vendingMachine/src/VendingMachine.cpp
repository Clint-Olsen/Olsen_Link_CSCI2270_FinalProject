#include "VendingMachine.h"
#include <iostream>
using namespace std;
VendingMachine::VendingMachine()
{
    for(int i=0; i<4;i++){
        hashTable[i]=NULL;
    }
}
void VendingMachine::inserNode(string name, int index){
    VendingItem *node = new VendingItem;
    if(hashTable[index]==NULL){
        hashTable[index]=node;
        node->itemName=name;
        node->left=NULL;
        node->right=NULL;
        node->row= index+1;
        //cout<<node->itemName<<endl;
    }
    else{
        VendingItem *temp=hashTable[index];
        while(temp->right!=NULL){
                temp=temp->right;
        }
        node->itemName=name;
        temp->right=node;
        node->right=NULL;
        node->left=temp;
        //cout<<node->itemName<<endl;
    }


}

void VendingMachine::displayItemsAndQuantity(){
    for(int i=0;i<4;i++){
        VendingItem *temp=hashTable[i];
        cout<<hashTable[i]->itemName<<": "<<hashTable[i]->quantity<<endl;
        while(temp->right!=NULL){
            temp=temp->right;
            cout<<temp->itemName<<": "<<temp->quantity<<endl;
        }
    }
}


VendingMachine::~VendingMachine()
{
    //dtor
}
