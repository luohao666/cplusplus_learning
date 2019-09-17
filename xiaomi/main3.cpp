#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


int main(int argc,char* argv[])
{
    //读数据
//    cout<<"io test"<<endl;

    int m;//搬运工
    int n;//办公室
    cin >> n >> m;
    if(m<1||m>10e5)
        return -1;
    if(n<1)
        return -1;

    vector<int> bags;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        bags.push_back(tmp);
    }

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=bags[i];
    }

    if(m>=sum)
        cout<<(n+1)<<endl;
        
    return 0;
}
