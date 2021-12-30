//this system to organize the data stucture which i added it to store my data
//  casher_system.h
//  casher
//  Created by Mac on 10/7/21.
#ifndef casher_system_h
#define casher_system_h
#endif /* casher_system_h */
#include <iostream>
#include "products_store.h"
place_store customer;// i creat the object here to remain lnked list have the data in every time need them.
using namespace std;
class casher
{
private:
    bool cont;
    bool user=false,owner=false;

public:
    casher( );
    void window();
    int print();
};
casher::casher()
{
    // we should make password for the owner.
    int x=0;
    cont=true;
    cout<<"who you\n" << "1-user\n"<< "2-owner of the system\n";
    cin>>x;
    if(x==1)
        user=true;
    else if(x==2)
        owner=true;
    else
        casher();
    casher::window();
}
void casher::window()
{
    //here ther are biiiiiiiiig mistak this object when i call this function  it will be created again.
    int choose,quantity;
    float price;
    long ID;
    string name;
    while(cont)
    {
        if(owner)
        {
            cout<<"1->add product in your shop?\n";
            cout<<"2->overview for my shop\n";
            cout<<"3->print all products\n";
            cout<<"what you want?";
                cin>>choose;
            if(choose==1)
            {
                cout<<"enter the ID of the product:";
                cin>>ID;
                cout<<"enter the quantity of the product:";
                cin>>quantity;
                    cout<<"enter the price of the product:";
                    cin>>price;
                    cout<<"enter the name of the product:";
                    cin>>name;
                    customer.add(quantity, price, ID, name);
            }
            else if(choose==2)
                customer.overview_for_the_shop();
            else if(choose==3)
                customer.print_all_products();
            else
                window();
            
        }
        else if(user)
           {
               cout<<"enter the ID of the product:";
               cin>>ID;
               cout<<"enter the quantity of the product:";
               cin>>quantity;
               customer.delete_product(ID, quantity);
           }
        cout<<"ther are another operation?\n"
        <<"1-yes      2-no\n";
        cin>>choose;
        if(choose==1)
        { cont=true; casher();}
        else
            cont =false;
    }
    if(user)
    customer.print_pill();
}
