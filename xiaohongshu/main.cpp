#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int dfs3(vector<vector<int> >& data,int i,int j)
{
    data[i][j]=0;//防止遍历过的再次进入
    int cur=1;
    //尝试向左
    if(i-1>=0&&data[i-1][j]==1)
        cur+=dfs3(data,i-1,j);
    //尝试向右
    if(i+1<data.size()&&data[i+1][j]==1)
        cur+=dfs3(data,i+1,j);
    //尝试向下
    if(j-1>=0&&data[i][j-1]==1)
        cur+=dfs3(data,i,j-1);
    //尝试向上
    if(j+1<data[0].size()&&data[i][j+1]==1)
        cur+=dfs3(data,i,j+1);

    return cur;    
}

//01数组岛的个数
int nums_land01(vector<vector<int> > data)
{
    if(data.empty())
        return -1;

    int res=0;
    int cols=data.size();
    int rows=data[0].size();
    for(int i=0;i<cols;i++)
    {
        for(int j=0;j<rows;j++)
        {
            if(data[i][j]==1)
            {
                dfs3(data,i,j);
                res++;
            }   
        }
    }
    return res;
}

int main(int argc,char* argv[])
{

    int n;
    cin >> n;
    vector<vector<int> > data(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int temp=0;
            cin >> temp;
            data[i][j]=temp;
        }

    cout<<nums_land01(data)<<endl;


    return 0;
}
