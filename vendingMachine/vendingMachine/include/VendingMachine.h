#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <iostream>
struct VendingItem{
    std::string itemName;//could not get this line to compile without including iostream
    int row;
    int quantity=10;
    int price;
    VendingItem *right;
    VendingItem *left;
};
class VendingMachine
{
    public:
        VendingMachine();

        void displayUserMenue();
        void displayItemsAndQuantity();
        void makePurchase(std::string item);
        VendingItem *findItem(std::string item);//this is a function that you cant call directly it is called by other functions
        void restock();
        void randomItem();
        void adminCode();
        void adminMenue();
        void replaceItem(std::string deleteItem,std::string newItem,int newPrice);
        void changePrice(std::string item, int nprice);
        void inserNode(std::string name,int index, float price);//for construction only
        virtual ~VendingMachine();
    protected:
    private:
        int revenue=0;
        VendingItem* hashTable[4];
};

#endif // VENDINGMACHINE_H
