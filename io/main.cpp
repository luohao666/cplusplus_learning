#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char* argv[])
{
    cout<<"io test"<<endl;

/* 
//读两个数据
    int n;
    int k;
    cin >> n >> k;
    //验证
    cout<<n<<endl;
    cout<<k<<endl;
*/

/* 
//读指定的n个数据
    int n;
    vector<int> data;
    int t;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        data.push_back(t);
    }
    //验证
    cout<<n<<endl;
    for(int i=0;i<n;i++)
        cout<<data[i]<<endl;
*/

//读n个数据,ctrl+d中断
    int s;
    vector<int> data;
    while(cin>>s)
    {
        data.push_back(s);
    }
    //验证
    //cout<<data.size()<<endl;
    //for(int i=0;i<data.size();i++)
    //    cout<<data[i]<<endl;

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
