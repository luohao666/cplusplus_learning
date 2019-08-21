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
    //a=dp_allbag(bags,T);
*/

/* 
    for(int i=0;i<a.size();i++)
        for(int j=0;j<a[0].size();j++)
        {
            cout<<a[i][j]<<endl;
        }
*/

 //   vector<Bag> best_bags;
 //   best_bags=get_best_bags(bags,a);

    //test
    // cout<<best_bags.size()<<endl;
    // for(int i=0;i<best_bags.size();i++)
    // {
    //     cout<<best_bags[i]._weight<<" ";
    //     cout<<best_bags[i]._value<<endl;
    // }

/* 
    int a1[3]={10,5,2};
    vector<int> bags_num(a1,a1+3);
    int a2[3]={1,2,2};
    vector<int> W(a2,a2+3);
    int a3[3]={6,10,20};
    vector<int> V(a3,a3+3);
    vector<Bag> bags;
    bags=make_bags(W,V);
    vector<vector<int> > a;
    a=dp_multibag(bags,8,bags_num);
    //test
    for(int i=0;i<a.size();i++)
        for(int j=0;j<a[0].size();j++)
        {
            cout<<a[i][j]<<endl;
        }
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

/* 
    //LCS
    string s1="ABCBDAB";
    string s2="BDCABA";
    vector<vector<int> > index;
    cout<<dp_lcs(s1,s2,index)<<endl;
    vector<char> s;
    int m=s1.length();
    int n=s2.length();
    get_lcs(index,s1,m,n,s);
    for(int i=0;i<s.size();i++)
        cout<<s[i]<<endl;

    vector<vector<int> > a;
    vector<char> ss;
    a=dp_lcs(s1,s2);
    get_lcs2(a,s1,m,n,ss);
    for(int i=0;i<ss.size();i++)
        cout<<ss[i]<<endl;
*/

/* 
    string s="javaej";
    cout<<dp_lps(s)<<endl;
*/

/* 
    int a[9]={2,4,-7,5,2,-1,2,-4,3};
    vector<int> v(a,a+9);
    cout<<max_subarray(v)<<endl;
*/

/* 
    int a[9]={3,1,4,1,5,9,2,6,5};
    vector<int> v(a,a+9);
    cout<<dp_lis(v)<<endl;
*/

/* 
    int a[11]={1,3,0,5,3,5,6,8,8,2,12};
    vector<int> v1(a,a+11);
    int a2[11]={4,5,6,7,8,9,10,11,12,13,14};
    vector<int> v2(a2,a2+11);
    cout<<greedy_activity_selector(v1,v2)<<endl;
*/

/* 
    int a[4]={1,2,4,5};
    vector<int> n_time(a,a+4);
    cout<<solve_boat(n_time)<<endl;
*/

/* 
    //int a[5]={3,2,1,0,4};
    int a[5]={2,3,1,1,4};
    vector<int> data(a,a+5);
    cout<<solve_jump(data)<<endl;
    cout<<sovle_jump2(data)<<endl;
*/

/* 
    int a[4]={10,2,1,6};
    vector<int> starts(a,a+4);
    int a2[4]={16,8,6,12};
    vector<int> ends(a2,a2+4);
    cout<<min_arrows(starts,ends)<<endl;
*/

/* 
    int a[6]={5,10,2,9,15,9};
    vector<int> childs(a,a+4);
    int a2[5]={6,1,20,3,8};
    vector<int> cookies(a2,a2+4);
    cout<<solve_cookie(childs,cookies)<<endl;
*/

/* 
    int a[10]={1,17,5,10,13,15,10,5,16,8};
    vector<int> data(a,a+10);
    cout<<solve_wiggle(data)<<endl;
*/

/* 
    string s="56317";
    cout<<remove_k_nums(s,3)<<endl;
*/

    int a[10]={2,5,2,1,2};
    vector<int> data(a,a+5);
    CombSum(data,5);
    return 0;
}
