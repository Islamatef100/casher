//it's casher program.
#include <iostream>
#include "casher_system.h"
using namespace std;
int main( )
{
    bool cont=true;
    while(cont)
    {
        int choose;
        casher c;
        cout<<"ther are another customer?\n"
        <<"1-yes      2-no\n";
        cin>>choose;
        if(choose==1)
            cont=true;
        else
            cont =false;
    }
}
