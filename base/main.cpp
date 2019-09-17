#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class base
{
    public:
        base()
        {
            a=1;
            b=2;
        }

        void show()
        {
            cout<<a<<endl;
            cout<<b<<endl;
        }

        void set(int aa,int bb)
        {
            a=aa;
            b=bb;
        }

    public:
        int b;
    private:
        int a;   
};

class drived: public base
{
    public:
        
        void show()
        {
            cout<<b<<endl;
        }

        void set(int bb)
        {
            b=bb;
        }
};

int main(int argc,char* argv[])
{
    drived d;

    d.show();

    d.set(5);

    d.base::set(3,4);

    d.show();

    d.base::show();



   return 0;
}

