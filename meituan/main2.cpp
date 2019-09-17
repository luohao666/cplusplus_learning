#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc,char* argv[])
{
    int n;
    cin >> n;
    if(n>100||n<=0)
        return -1;
    
    string res="";
    bool flag=true;

    for(int i=1;i<=n;i++)
    {
        if(i%2)
            res+="A";
        else
        {
            if(flag)
            {
                res+="B";
                flag=false;
            }
            else
            {
                res+="C";
                flag=true;
            }
        }
    }
    cout << res <<endl;

    return 0;
}
