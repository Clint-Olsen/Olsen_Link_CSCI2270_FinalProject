#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <iostream>
#include <string>
struct VendingItem{
    std::string itemName;
    int row;
    int quantity=5;
    int price;
    VendingItem *right;
    VendingItem *left;
};
class VendingMachine
{
    public:
        VendingMachine();

        void displayItemsAndQuantity();
        void makePurchase(std::string item);
        void restock();
        void randomItem();
        void freeItem();
        int revenueWithdrawal();
        void replaceItem(std::string deleteItem,std::string newItem,int newPrice);
        void changePrice(std::string item, int nprice);
        void inserNode(std::string name,int index, float price);//for construction only
        void deleteVendingMachine();
        virtual ~VendingMachine();
    protected:
    private:
        int revenue=0;
        VendingItem* hashTable[4];
        VendingItem *findItem(std::string item);
        bool itemStuck=false;
        std::string nameOfItemStuck;
};

#endif // VENDINGMACHINE_H
