#include "complex.h"
#include <iostream>
#include "mystring.h"
using namespace std;

int main(int argc,char* argv[])
{
    complex a1;
    complex a2(1,2);

    a1+=a2;

    double a3=1;
    complex a4=a1+a3;
    complex a5=a3+a1;

    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;
    cout << a4 << endl;
    cout << a5 << endl;

    Mystring s1;
    cout << s1 << endl;
    Mystring s2("Hello");
    cout << s2 << endl;
    Mystring s3(s2);
    cout << s3 << endl;
    Mystring s4("World");
    cout << s4 << endl;
    s4=s3;
    cout << s4 << endl;

    return 0;
}