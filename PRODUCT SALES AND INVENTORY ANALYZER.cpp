#include <iostream>
#include <vector>
#include<cstdlib>
#define taxRateDirective 15

using namespace std;

const int taxRateConst{15};

int main() {
    cout<<"WELCOME TO PRODUCT SALES AND INVENTORY ANALYZER PROGRAM!"<<'\n';
    cout<<"---------------------------------------------------------------------------"<<"\n";
    cout<<"This program helps store managers track product sales and inventory levels."<<endl<<"\nReminder: This program is written in C++, a compiled language.\nPlease ensure you compile the code before running it"<<'\n';
    cout<<"---------------------------------------------------------------------------"<<"\n";

    cout<<"Product Categories: |  1 - Electronics  |  2 - Groceries  |  3 - Clothing  |  4 - Stationery  |  5 - Miscellaneous\n";
    string productName;
    int productCatagory;
    int inventoryQuantity;
    float pricePerUnit;
    int itemsSold;
    cout<<"Enter the product name:";
    cin>>productName;
    cout<<"Enter the product catagory (1-5):";
    cin>>productCatagory;
    if (productCatagory>=1 and productCatagory<=5) {
        cout<<"Enter the initial inventory quantity:";
        cin>>inventoryQuantity;
        cout<<"Enter the product price per unit:";
        cin>>pricePerUnit;
        cout<<"Enter the number of items sold:";
        cin>>itemsSold;
        if (inventoryQuantity<itemsSold) {
            cout<<"QUANTITY IS NOT POSSIBLE!"<<'\n';
            return 0;
        }
    }

    string catagory;

    switch (productCatagory) {
        case 1:catagory="Electronics"; break;
        case 2:catagory="Groceries";break;
        case 3:catagory="Clothing";break;
        case 4:catagory="Stationery";break;
        case 5:catagory="Miscellaneous";break;
        default: {
            catagory="INVALID CHOICE!!!";
        }

    }
    cout<<"---------------------------------------\n-------Inventory and Sales Report--------\n---------------------------------------\n";
    cout<<"Prodcut Name: "<<productName<<"\n";
    cout<<"Prodcut Catagory: "<<catagory<<"\n";
    if (productCatagory<1 or productCatagory>5) {
        return 0;
    }
    cout<<"Prodcut Intial Inventory Quantity: "<<inventoryQuantity<<"\n";
    cout<<"Prodcut Price per Unit: $"<<pricePerUnit<<"\n";
    cout<<"Number of items Sold: "<<itemsSold<<"\n";

    int newInventory= inventoryQuantity-itemsSold;
    float totalSales= itemsSold*pricePerUnit;
    string status;

    auto salesCopy (totalSales);
    // Direct Initialization
    decltype(inventoryQuantity) inventoryCopy{inventoryQuantity};
    // List Initialization


    if (newInventory<10) {
        status="LOW INVENTORY";
    }
    else {
        status="SUFFICIENT INVENTORY";
    }


    cout<<"-------------------------------------"<<"\n";
    cout<<"NEW INVENTORY: "<<newInventory<<"\n";
    cout<<"Total Sales Amount: $"<<totalSales<<"\n";
    cout<<"-------------------------------------"<<"\n";
    cout<<"Inventory Status: "<<status<<"\n";
    cout<<"---------------------------------------\n -------HELPER VALUES------- \n---------------------------------------\n";
    cout<<"Total Sales Amount (Copy using `auto`): $"<<salesCopy<<"\n";
    cout<<"Initial Inventory (Using `decltype`): "<<inventoryCopy<<"\n";
    cout<<"---------------------------------------\n-----RECEIPT -----\n---------------------------------------\n";
    int i;
    for (i=1; i<=itemsSold; i++) {
        cout<<"ITEM "<<i<<": $"<<pricePerUnit<<"\n";
    }
    cout<<"--------------------------------------\n";
    cout<<"Total(without tax): $"<<salesCopy<<endl;
    cout<<"Tax Rate: "<<taxRateConst<<"%\n";
    cout<<"Tax: $"<<salesCopy*taxRateDirective/100<<endl;
    cout<<"Total: $"<<salesCopy+(salesCopy*taxRateDirective/100);

    cout<<"\n---------------------------------------\nProcessing complete! Thank you for using the Product Sales and Inventory Analyzer.";

}