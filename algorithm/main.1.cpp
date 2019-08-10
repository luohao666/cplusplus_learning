#include <iostream>
#include <vector>
#include <algorithm>
#include "my_algorithm.h"

using namespace std;

int main(int argc,char* argv[])
{
    cout<<"algorithm test"<<endl;

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
    vector<int> data1;
    vector<int> data2;
    int t;

    int T;
    cin>>T;//limitWeight
    cin>>n;//nums of bags

    for(int i=0;i<n;i++)
    {
        cin>>t;
        data1.push_back(t);
    }
    for(int i=0;i<n;i++)
    {
        cin>>t;
        data2.push_back(t);
    }
    //验证
    // cout<<n<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<data1[i]<<" ";
    //     cout<<data2[i]<<endl;
    // }

    vector<Bag> bags;
    bags=make_bags(data1,data2);
    vector<vector<int> > a;
    a=dp_01bag(bags,T); 
    for(int i=0;i<a.size();i++)
        for(int j=0;j<a[0].size();j++)
        {
            cout<<a[i][j]<<endl;
        }

    vector<Bag> best_bags;
    best_bags=get_best_bags(bags,a);

    //test
    // cout<<best_bags.size()<<endl;
    // for(int i=0;i<best_bags.size();i++)
    // {
    //     cout<<best_bags[i]._weight<<" ";
    //     cout<<best_bags[i]._value<<endl;
    // }
*/

    //3 people 3 times
//    cout<<dp_jgch(3,3)<<endl;

/*
    //penny
    int a[3]={1,2,4};
    vector<int> penny(a,a+3);
    cout<<dp_penny(penny,3)<<endl;
*/

/*
    //step square
    int a[3]={1,2,3};
    vector<int> v1(a,a+3);
    int a2[3]={1,1,1};
    vector<int> v2(a2,a2+3);
    vector<vector<int> > map;
    map.push_back(v1);
    map.push_back(v2);

    cout<<dp_step_square(map,2,3)<<endl;
*/

    //LCS
    string s1="ABCBDAB";
    string s2="BDCABA";
    cout<<dp_lcs(s1,s2)<<endl;


    return 0;
}
