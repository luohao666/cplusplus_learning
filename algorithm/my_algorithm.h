#ifndef __MY_ALGORIHTM_H__
#define __MY_ALGORIHTM_H__

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

/***************************************************************************/
/*动态规划 */
/***************************************************************************/

//dynamic plan :01 bag
//question:
//w1,...,wn
//v1,...,vn
//bw...max weight of bag
//get the max value?
struct Bag
{
    Bag(int w,int v):_weight(w),_value(v){}

    int _weight;
    int _value;
};

vector<Bag> make_bags(const vector<int>& weights,const vector<int>& values)
{
    vector<Bag> bags;
    for(int i=0;i<weights.size();i++)
    {
        Bag bag(weights[i],values[i]);
        bags.push_back(bag);
    }
    return bags;
} 

vector<vector<int> > dp_01bag(const vector<Bag>& bags,int limitWeight)
{
    int numsOfBags=bags.size();
    vector<vector<int> > a(numsOfBags+1);
    for(int i=0;i<a.size();i++)
        a[i].resize(limitWeight+1);

    for(int j=0;j<=limitWeight;j++)//weights
        for(int i=0;i<=numsOfBags;i++)//bags
        {
            if(i==0||j==0)
            {
                a[i][j]=0;
            }
            else
            {
                if(bags[i-1]._weight>j)
                    a[i][j]=a[i-1][j];
                else
                    a[i][j]=max(a[i-1][j],a[i-1][j-bags[i-1]._weight]+bags[i-1]._value);
            }
        }
    return a;
}

vector<Bag> get_best_bags(const vector<Bag>& bags, const vector<vector<int> >& a)
{
    vector<Bag> best_bags;
    int rows=a.size();
    int cols=a[0].size();
    int best_value=a[rows-1][cols-1];
    int temp_value=best_value;

    for(int i=bags.size();i>0;i--)
    {
        if(temp_value==0)
            break;
        
        if(a[i][cols-1]>a[i-1][cols-1])
        {
            cout<<a[i][cols-1]<<endl;
            cout<<a[i-1][cols-1]<<endl;
            best_bags.push_back(bags[i-1]);
            temp_value-=bags[i-1]._value;
        }
    }
    return best_bags;
}

//dynamic plan :ji gu chuan hua
//question:
//n people
//m times
//differ returns?

int dp_jgch(int n,int m)
{
    //2D array:take m+1 to arrive n
    vector<vector<int> > a(m,vector<int>(n,0));

    //end cond
    a[0][1]=1;
    a[0][n-1]=1;

    for(int i=1;i<m;i++)
        for(int j=0;j<n;j++)
        {
            a[i][j]=a[i-1][(j+1)%n]+a[i-1][(j+n-1)%n];
        }

    return a[m-1][0];
}

int dp_upstairs(int m)
{
    vector<int> a(m);
    a[0]=1;
    a[1]=2;
    //ways to reach i+1
    for(int i=2;i<m;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }

    return a[m-1];
}

//penny problem
//penny[],aim
//n,m
//00000
//1****
//1****
//1****
int dp_penny(const vector<int>& penny,int aim)
{
    //2D vector
    int n=penny.size()+1;
    int m =aim+1;
    
    vector<vector<int> > a(n,vector<int>(m,0));


    //init
    for(int i=1;i<n;i++)
    {
        a[i][0]=1;
    }

    for(int i=1;i<m;i++)
    {
        if(i%penny[0]==0)
            a[1][i]=1;
    }

    //test
    // for(int i=0;i<n;i++)
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<a[i][j]<<endl;
    //     }

    for(int i=2;i<n;i++)
        for(int j=1;j<m;j++)
        {
            if(j>=penny[i-1])
            {
                a[i][j]=a[i-1][j]+a[i][j-penny[i-1]];
            }
            else
            {
                a[i][j]=a[i-1][j];
            }
        }
    return a[n-1][m-1];
}

//step square problem
//vector<vector<int> >& map
//rows,cols
//00000
//0****
//0****
//0****
int dp_step_square(const vector<vector<int> >& map,int rows,int cols)
{
    //2D vector
    int m=rows+1;
    int n=cols+1;
    vector<vector<int> > dist(m,vector<int>(n,0));

    //init
    for(int i=1;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<i;j++)
        {
            sum+=map[0][j];
        }
        dist[1][i]=sum;
    }

    for(int i=1;i<m;i++)
    {
        int sum=0;
        for(int j=0;j<i;j++)
        {
            sum+=map[j][0];
        }
        dist[i][1]=sum;
    }

    //test
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            cout<<dist[i][j]<<endl;
        }

    for(int i=2;i<m;i++)
    {
        for(int j=2;j<n;j++)
        {
            dist[i][j]=min(dist[i-1][j],dist[i][j-1])+map[i-1][j-1];
        }
    }

    return dist[m-1][n-1];
}

//longest common subsequence,LCS
/*
a[i,j]=0;i=0||j=0
a[i,j]=c[i-1,j-1]+1;i,j>0,xi=yj
a[i,j]=max{c[i-1,j]+c[i,j-1]};i,j>0,xi!=yj
*/

//get length is easy
vector<vector<int> > dp_lcs(string s1,string s2)
{
    //2d array
    int m=s1.size()+1;
    int n=s2.size()+1;
    vector<vector<int> > a(m,vector<int>(n,0));

    //init

    //
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
        {
            if(s1[i-1]==s2[j-1])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    
    return a;
}

void get_lcs2(const vector<vector<int> >& a,string s1,int m, int n,vector<char>& s)
{
    int k=a[m][n];
    cout<<k<<endl;
    s.resize(k);
    while(k>0)
    {
        if(a[m][n]==a[m-1][n])
            m--;
        else if(a[m][n]==a[m][n-1])
            n--;
        else
        {
            s[--k]=s1[m-1];
            m--;
            n--;
        }
    }
}

//we should get str
int dp_lcs(string s1,string s2,vector<vector<int> >& index)
{
    //2d array
    int m=s1.size()+1;
    int n=s2.size()+1;
    vector<vector<int> > a(m,vector<int>(n,0));
    index=a;
    //init
    for(int i=0;i<m;i++)
        index[i][0]=-2;// no direction

    for(int i=0;i<n;i++)
        index[0][i]=-2;// no direction
    //
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                a[i][j]=a[i-1][j-1]+1;
                index[i][j]=0;// left up
            }
            else
            {
                if(a[i-1][j]>=a[i][j-1])
                {
                    a[i][j]=a[i-1][j];
                    index[i][j]=-1;// up
                }
                else
                {
                    a[i][j]=a[i][j-1];
                    index[i][j]=1;// left 
                }
            }
        }
    
    return a[m-1][n-1];
}

void get_lcs(const vector<vector<int> >& index,string s1,int m, int n,vector<char>& s)
{
    if(m==0||n==0)
        return;
    
    if(index[m][n]==0)
    {
        get_lcs(index,s1,m-1,n-1,s);
    //    cout<<s1[m-1]<<endl;
        s.push_back(s1[m-1]);
    }
    else if(index[m][n]==-1)
    {
        get_lcs(index,s1,m-1,n,s);
    }
    else
    {
        get_lcs(index,s1,m,n-1,s);
    }
}

//longest common substring
//get length is easy
int dp_lcsubstring(string s1,string s2)
{
    //2d array
    int m=s1.size()+1;
    int n=s2.size()+1;
    vector<vector<int> > a(m,vector<int>(n,0));

    //init

    //
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
        {
            if(s1[i-1]==s2[j-1])
                a[i][j]=a[i-1][j-1]+1;
            else
            ;
        }
    
    return a[m-1][n-1];
}

//longest palindrome subsequence,LPS
/*
1***
*1**
**1*
***1
 */
int dp_lps(string s)
{
    //2D array
    int n=s.length();
    vector<vector<int> > a(n,vector<int>(n,0));
    
    //init
    for(int i=0;i<n;i++)
    {
        a[i][i]=1;
    }

    for(int len=2;len<=n;len++)
        for(int i=0;i<n;i++)
        {
            int j=i+len-1;
            if(j<n)
            {
                if(s[i]==s[j])
                    a[i][j]=a[i+1][j-1]+2;
                else
                    a[i][j]=max(a[i+1][j],a[i][j-1]);
            }
        }
    return a[0][n-1];
}

//最大连续子数组
//a[i]=max(a[i-1]+v[i],v[i])
int max_subarray(vector<int> v)
{
    //1D array
    int n=v.size();
//    vector<int> a(n,0);    
    int temp=v[0];
    int max=v[0];

    for(int i=1;i<n;i++)
    {
        int temp=temp+v[i];
        if(temp<v[i])
            temp=v[i];
        if(temp>max)
            max=temp;
    }
    return max;
}

//最长递增子序列
//a[i]=max{a[i-1]},if a[i]<=a[j],j=0,,,i-1
//a[i]=max{a[i-1]}+1,if a[i]>a[j]
int dp_lis(vector<int> v)
{
    //1D array
    int n=v.size();
    vector<int> a(n,1);

    //init

    for(int i=1;i<n;i++)
    {
        bool flag=true;
        for(int j=0;j<i;j++)
        {
            if(v[i]<=v[j])
                flag=false;
        }
        if(flag)
            a[i]=a[i-1]+1;
        else
            a[i]=a[i-1];
    }
    return a[n-1];
}

//字符串最短编辑距离


/***************************************************************************/
/*贪心算法 */
/***************************************************************************/
//活动选择问题
struct ACT
{
    ACT(int begin,int end):_begin(begin),_end(end){}
    int _begin;
    int _end;
};

bool cmp1(const ACT& act1,const ACT& act2)
{
    return act1._end<act2._end;
}

bool cmp(const pair<int,int>& act1,const pair<int,int>& act2)
{
    return act1.second<act2.second;
}

int greedy_activity_selector(const vector<int>& v1,const vector<int>& v2)
{
    int n=v1.size();
    vector<pair<int,int> > acts;
    for(int i=0;i<n;i++)
    {
        acts.push_back(make_pair(v1[i],v2[i]));
    }
    sort(acts.begin(),acts.end(),cmp);

    int num=1;
    int i=0;
    for(int j=1;j<n;j++)
    {
        if(acts[j].first>=acts[i].second)
        {
            i=j;
            num++;
        }
    }
    return num;
}

//钱币找零问题
//count={3,0,2,1,0,3,5}
//value={1,2,5,10,20,50,100}
//支付K元，至少???
int solve_money(const vector<int>& counts,const vector<int>& values,int K)
{
    const int N=counts.size();
    int num=0;
    for(int i=N-1;i>=0;i--)
    {
        int c=min(K/values[i],counts[i]);
        K=K-values[i]*c;
        num+=c;
    }
    if(K>0)
        num=-1;
    return num;
}

//再论背包问题
//多机调度问题

//小船过河
//一只船乘两人，载n人过河
int solve_boat(const vector<int>& n_time)
{
    //n_time已经排序完成哦
    int N=n_time.size();
    int sum_time=0;
    while(N>3)
    {
        sum_time+=min(n_time[0]+2*n_time[1]+n_time[N-1],2*n_time[0]+n_time[N-2]+n_time[N-1]);
        N=N-2;
    }
    if(N==3)
        sum_time+=n_time[0]+n_time[1]+n_time[2];
    else if(N==2)
        sum_time+=n_time[1];
    else
        sum_time=n_time[0];

    return sum_time;
    
}

//区间覆盖问题

//跳跃问题
//能否跳到最后位置
bool solve_jump(const vector<int>& data)
{
    vector<int> index;//能跳到的最大距离
    for(int i=0;i<data.size();i++)
        index.push_back(i+data[i]);
    
    int cur=0;//当前指针
    int cur_max=0;//当前最大指针
    
    while(cur<data.size()&&cur<=cur_max)
    {
        if(cur_max<index[cur])
            cur_max=index[cur];
        cur++;
    }
    if(cur==data.size())//cur指向最后一个元素
        return true;
    return false;
}
//跳跃到最后的最小次数
//贪心思想:尽量不跳，逼不得已再跳
int sovle_jump2(const vector<int>& data)
{
    if(data.size()<2)
        return data.size();

    int num=1;
    int cur_len=data[0];
    int pre_len=data[0];

    for(int i=1;i<data.size();i++)
    {
        if(i>cur_len)
        {
            cur_len=pre_len;
            num++;
        }
        if(data[i]+i>pre_len)
            pre_len=data[i]+i;
    }
    return num;
}

//射气球问题
//最少射箭数量
struct Segment
{
    Segment(int s,int e):_start(s),_end(e){};
    int _start;
    int _end;
};

bool cmp_segments(const Segment& s1,const Segment& s2)
{
    return s1._start<s2._start;
}

int min_arrows(const vector<int>& starts,const vector<int>& ends)
{
    vector<Segment> segments;
    for(int i=0;i<starts.size();i++)
    {
        Segment s(starts[i],ends[i]);
        segments.push_back(s);
    }
    sort(segments.begin(),segments.end(),cmp_segments);
    int num=1;
    int start=segments[0]._start;
    int end=segments[0]._end;
    for(int i=1;i<segments.size();i++)
    {
        if(segments[i]._start<=end)//取交集，直到没有交集
        {
            start=segments[i]._start;
            if(segments[i]._end<end)
                end=segments[i]._end;
        }
        else//没有交集，重新指定起始点
        {
            num++;
            start=segments[i]._start;
            end=segments[i]._end;
        }
    }
    return num;
}

//分饼干问题
int solve_cookie(vector<int>& childs,vector<int>& cookies)
{
    sort(childs.begin(),childs.end());
    sort(cookies.begin(),cookies.end());
    int child=0;
    int cookie=0;

    while(child<childs.size()&&cookie<cookies.size())
    {
        if(childs[child]<=cookies[cookie])
            child++;
        cookie++;
    }
    return child;
}

//摆动序列问题
int solve_wiggle(const vector<int>& data)
{
    int n=data.size();
    if(n<2)
        return data.size();

    int num=1;
    const int BEGIN=0;
    const int UP=1;
    const int DOWN=2;
    int STATE=BEGIN;

    for(int i=1;i<n;i++)
    {
        switch(STATE)
        {
            case BEGIN:
                if(data[i-1]<data[i])
                {
                    STATE=UP;
                    num++;
                }
                else if(data[i-1]>data[i])
                {
                    STATE=DOWN;
                    num++;
                }
                break;
            case UP:
                if(data[i-1]>data[i])
                {
                    STATE=DOWN;
                    num++;
                }
                break;
            case DOWN:
                if(data[i-1]<data[i])
                {
                    STATE=UP;
                    num++;
                }
                break;
        }
    }
    return num;
}

//移除k个数字
//178543 4
//13
string remove_k_nums(string s,int k)
{
    string res="";
    const int n=s.size();
    vector<char> data;
    for(int i=0;i<n;i++)
        data.push_back(s[i]);
    
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(data[j]<data[j+1])
                continue;
            else
            {
                data[j]='a';
                break;
            }
        }

        for(int j=0;j<n-i;j++)
        {
            if(data[j]=='a')
            {
                data[j]=data[j+1];
                data[j+1]='a';
            }
        }
    }

    for(int i=0;i<n-k;i++)
        res+=data[i];
    return res;
}

//旅行商问题

#endif