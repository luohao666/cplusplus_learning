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

//读n个数据,ctrl+d中断
    int s;
    vector<int> data;
    while(cin>>s)
    {
        data.push_back(s);
    }

    int xiaomi=0;
    int dami=0;

    int i=0;
    int j=data.size()-1;
    bool flag=true;
    while(i<j)
    {
        if(flag)
        {
            flag=false;
            if(data[i]>=data[j])
            {
                xiaomi+=data[i];
                i++;
            }
            else
            {
                xiaomi+=data[j];
                j--;
            }
        }
        else
        {            
            flag=true;
            if(data[i]>=data[j])
            {
                dami+=data[i];
                i++;
            }
            else
            {
                dami+=data[j];
                j--;
            }
        }
        
    }
    if(xiaomi>=dami)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
