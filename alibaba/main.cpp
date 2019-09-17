#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


bool isInside(vector<char>& sign,char c)
{
    vector<char>::iterator it;
    it=find(sign.begin(),sign.end(),c);
    if (it!=sign.end())//如果不是sign里的字符
        return true;
    else
        return false;
}


int dfs(vector<vector<char>>& data, vector<char>& sign, int row, int col) 
{
    //修改data，防止再次进入
    data[row][col]='0';

    int steps=1;
    //尝试向上走
    if (row - 1 >= 0&&isInside(sign,data[row-1][col])) {
        steps+=dfs(data, sign, row - 1, col);
    }
    //尝试向下走
    if (row + 1 < data.size()&&isInside(sign,data[row+1][col])) {
        steps+=dfs(data, sign, row + 1, col);
    }
    //尝试向左走
    if (col - 1 >= 0&&isInside(sign,data[row][col-1])) {
        steps+=dfs(data, sign, row, col - 1);
    }
    //尝试向右走
    if (col + 1 < data[0].size()&&isInside(sign,data[row][col+1])) {
        steps+=dfs(data, sign, row, col + 1);
    }

    return steps;
}


int main(int argc,char* argv[])
{
    //读数据
    string s;
    string s1;
    cin >> s >> s1;
   
    stringstream ss(s);
    vector<string> vs;
    vector<string> vs1;
    string temp;
    while(getline(ss, temp, ','))
        vs.push_back(temp);
    stringstream ss1(s1);
    while(getline(ss1, temp, ','))
        vs1.push_back(temp);

    //二维数组
    vector<vector<char> > data(vs.size(),vector<char>(vs[0].size(),' '));
    for(int i=0;i<data.size();i++)
    {
        for(int j=0;j<data[0].size();j++)
        {
            data[i][j]=vs[i][j];
        }
    }
    vector<char> sign(vs1.size(),' ');
    for(int i=0;i<sign.size();i++)
    {
        sign[i]=vs1[i][0];
    }


    int ans=1;
    for(int i=0;i<data.size();i++)
    {
        for(int j=0;j<data[0].size();j++)
        {
            if(isInside(sign,data[i][j]))
            {
                int t = dfs(data,sign,i,j);
                if(t>ans)
                    ans=t;
            }
        }
    }
    
    cout<<ans<<endl;

    return 0;
}
