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

    int T;//样例个数
    cin >> T;
    vector<int> ans;
    for(int i=0;i<T;i++)
    {
        int K;//最小间隔
        int M;//固定天数
        cin >> K >> M;
        vector<int> data;
        int res=0;
        for(int j=0;j<M;j++)
        {
            int temp;
            cin >> temp;
            data.push_back(temp);
        }

        res+=data.size();
        res+=(data[0]-0-1)/(K+1);
        for(int j=1;j<M;j++)
        {
            res+=(data[j]-data[j-1]-1)/(K+2);
        }
        res+=(30-data[M-1]-0)/(K+1);
        ans.push_back(res);
        //cout<<res<<endl;
    }

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;

    return 0;
}
