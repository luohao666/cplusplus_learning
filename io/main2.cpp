#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char* argv[])
{
//读n个数据,ctrl+d中断
    int s;
    vector<int> data;
    while(cin>>s)
    {
        data.push_back(s);
    }

    int res=0;
    for(int i=0;i<data.size();i++)
    {
        int t=data[i];
        int ans=0;
        int count=0;
        while(ans<t)
        {
            count++;
            ans=count*(count+1)/2;
        }
        count--;
        res=1+count*(count-1)/2-count+1;
        ans=count*(count+1)/2;
        int diff=t-ans;
        if(diff==count+1)
            res+=diff-2;
        else
            res+=diff;
        
        cout<<res<<endl;
    }
    return 0;
}
