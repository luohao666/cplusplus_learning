#include <iostream>
#include "mystl.h"

using namespace std;

int main(int argc,char* argv[])
{
    cout<<"mystl"<<endl;
    cout<<"using set"<<endl;
    using_set();
    cout<<"using multiset"<<endl;
    using_multiset();
    cout<<"using map"<<endl;
    using_map();
    cout<<"using multimap"<<endl;
    using_multimap();

    cout<<"using unordered set"<<endl;
    using_unordered_set();
    cout<<"using unordered multiset"<<endl;
    using_unordered_multiset();
    cout<<"using unordered map"<<endl;
    using_unordered_map();
    cout<<"using unordered multimap"<<endl;
    using_unordered_multimap();

    return 0;
}