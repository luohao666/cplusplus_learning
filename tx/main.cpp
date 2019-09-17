#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

bool isEven(int data)
{
    if(data%2)
        return true;
    else
        return false;
}

int main(int argc,char* argv[])
{
    //读数据
//    cout<<"io test"<<endl;

    int m;
    int n;
    cin >> m >> n;
    if(m<1||m>10e5)
        return -1;
    if(n<1)
        return -1;

    vector<int> bags;
    vector<int> keys;
    for(int i=0;i<m;i++)
    {
        int tmp;
        cin>>tmp;
        bags.push_back(tmp);
    }
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        keys.push_back(tmp);
    }

    int res=0;
    int evenOfBags=0;
    int oddOfBags=0;
    int evenOfKeys=0;
    int oddOfKeys=0;

    for(int i=0;i<m;i++)
    {
        if(isEven(bags[i]))
            evenOfBags++;
    }
    oddOfBags=m-evenOfBags;

    for(int i=0;i<n;i++)
    {
        if(isEven(keys[i]))
            evenOfKeys++;
    }
    oddOfKeys=n-evenOfKeys;

    res=min(evenOfBags,oddOfKeys)+min(oddOfBags,evenOfKeys);
    cout<<res<<endl;

    return 0;
}
