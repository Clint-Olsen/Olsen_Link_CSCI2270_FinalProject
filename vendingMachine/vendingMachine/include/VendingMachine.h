#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <iostream>
struct VendingItem{
    std::string itemName;//could not get this line to compile without including iostream
    int row;
    int quantity=10;
    VendingItem *right;
    VendingItem *left;
};
class VendingMachine
{
    public:
        VendingMachine();
        void displayItemsAndQuantity();
        void makePurchase();
        void restock();
        void inserNode(std::string name,int index);//for construction only
        virtual ~VendingMachine();
    protected:
    private:
        VendingItem* hashTable[4];
};

#endif // VENDINGMACHINE_H
