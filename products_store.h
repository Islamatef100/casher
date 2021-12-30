// this is linked list to stor all the products and this prise and the quantity.
//  products_store.h
//  casher
//  Created by Mac on 10/7/21.
#ifndef products_store_h
#define products_store_h
#endif /* products_store_h */
#include <iostream>
#include <string>
using namespace std;
class node
{
public:
    int quantity;
    float price;
    long ID;
    string name;
    node* next;
};
class place_store
{
private:
    node*head;
   static long  budget_of_the_shop,profits_of_th_shop;
    long paymony=0;
public:
    place_store();
    void add(int q,float p,long i,string n);//when i buy products for my shop.
    void delete_product(long i,int q);
    // when the shop sell products then the shop losed the product.
    void overview_for_the_shop();
    void print_pill();
    void print_all_products();
};
long place_store::budget_of_the_shop=0;
long place_store::profits_of_th_shop=0;
place_store:: place_store()
{
    head=nullptr;
    paymony=0;
}
void place_store::add(int q,float p,long i,string n)
{
    node*temp=new node;
    temp->quantity=q;
    temp->price=p;
    temp->ID=i;
    temp->name=n;
    temp->next=nullptr;
    budget_of_the_shop+=(p*q);
    /*
     note that i can not delete it if i delete it then i delete all node not this node can be accesed by temp and head and if it done all operation will be first node and deleted. tace care.
     */
    if(head==nullptr)
    {   head=temp;    cout<<"you add:"<<head->ID<<endl;}
    //cout<<"u add:"<<head->name<<endl;}
    //    delete temp;
    else
    {
        node*temp2=head;
        while(temp2->next!=nullptr&&temp2->ID!=i)
        {
            temp2=temp2->next;
        }
        if(temp2->ID==i)
        {
            temp2->quantity+=q;
            cout<<"this product already exist and we added to id ("<<q<<") to "<<temp2->ID<<endl;
        }
        else
        {
            temp2->next=temp;
            cout<<"you add:"<<temp2->next->ID<<endl;
        }
    }
}
void place_store:: print_all_products()
{
    if(head==nullptr)
        cout<<"you have not any products.\n";
    else
    {
        node*temp=new node;
        temp=head;
        while(temp!=nullptr)
        {
            cout<<"quantity=>"<<temp->quantity<<endl;
            cout<<"price=>"<<temp->price<<endl;
            cout<<"ID=>"<<temp->ID<<endl;
            cout<<"name=>"<<temp->name<<endl;
            temp=temp->next;
        }
    }
}
void place_store:: delete_product(long i,int q)
{
    //to do constractor just in delete.
    if(head==nullptr)
        cout<<"u have not any prodect.\n";
    else{
        node*temp=head;
        node*temp2 = nullptr;
        
        while(temp!=nullptr && (temp->ID)!=i)
        {
            temp2=temp;
            temp=temp->next;
        }
        if(temp==nullptr)
            cout<<"This product is not available\n";
        else
        {
              //  profits_of_th_shop+=(temp->price*q);
                if(q>temp->quantity)
                    cout<<"sorry!!you have not this quantity you just have "<<temp->quantity<<endl;
                else if(q<(temp->quantity))
                    {
                        budget_of_the_shop-=(temp->price*q);
                        profits_of_th_shop+=(temp->price*q);
                        temp->quantity-=q;
                        paymony+=(temp->price*q);
                    }
                    else{
                        paymony+=(temp->price*q);
                        budget_of_the_shop-=(temp->price*q);
                        profits_of_th_shop+=(temp->price*q);
                             if(temp2==nullptr)
                            {
                                temp2=temp;
                                temp=temp->next;
                                head=temp;//its very important take care becouse in the next time in any oberation i start from head so head is very important to be important for me.
                                delete temp2;
                                cout<<"the product is deleted.\n";
                            }
                            else if(temp->next=nullptr)
                            {
                                temp2->next=nullptr;
                                delete temp;
                            }
                            else
                            {
                                temp2->next=temp->next;
                                cout<<"this all product is deleted\n";
                                    delete temp;
                            }
                            
                    }
                
                 }
            //   delete temp2;
            /*
             note that i can not delete it if i delete it i don't delete the pointer but i delete all node so the next node ant the previose node will be losed so take care whin u delete any node
             */
             }
        }
void place_store::overview_for_the_shop()
{
    cout<<"you have in your shop ("<<budget_of_the_shop<<") dolares\n";
    cout<<"you sold products by ("<<profits_of_th_shop<<") dolares$\n";
}
void place_store::print_pill()
{
    cout<<"you should pay ("<<paymony<<") dolares$\n";
    paymony=0;
}
