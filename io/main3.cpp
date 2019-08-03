#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char* argv[])
{
    cout<<"io test"<<endl;

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
//    cout<<n<<endl;
//    for(int i=0;i<n;i++)
//        cout<<data[i]<<endl;

    //找到数组中降序头尾
    int start=0;
    int end=0;
    bool first=true;
    bool flag=false;
    for(int i=0;i<n-1;i++)
    {
        if(data[i+1]<data[i])
        {
            if(first)
            {
                start=i;
                first=false;
                flag=true;
            }
            if(i==n-2)//降序排列54321
                end=i+1;
        }
        else        
        {
            if(flag)
            {
                end=i;
                break;
            }
        }
    }
//    cout<<start<<endl;
//    cout<<end<<endl;
    //将其升序排列
    while(start<end)
    {
        int temp=0;
        temp=data[end];
        data[end]=data[start];
        data[start]=temp;
        start++;
        end--;
    }
    //for(int i=0;i<n;i++)
    //    cout<<data[i]<<endl;

    //判断整个数组是否为升序
    for(int i=0;i<n-1;i++)
    {
        if(data[i+1]<data[i])
        {
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}
