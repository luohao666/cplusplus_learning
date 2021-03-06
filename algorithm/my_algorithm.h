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
                if(bags[i-1]._weight>j)//要不要第i个物品
                    a[i][j]=a[i-1][j];
                else
                    a[i][j]=max(a[i-1][j],a[i-1][j-bags[i-1]._weight]+bags[i-1]._value);
            }
        }
    
    /* 
    //we need best bags and nums
    vector<int> res(numsOfBags,0);
    int i=numsOfBags;//包的种类
    int j=limitWeight;//
    while(i)
    {
        if(a[i][j] == (a[i-1][j-bags[i-1]._weight]+bags[i-1]._value))
        {
            res[i-1] = 1;
            j = j-bags[i-1]._weight;
        }
        i--;
    }

    for(int ii=0;ii<res.size();ii++)
        cout<<res[ii]<<" ";
    cout<<endl;
    */
   
    return a;
}

vector<vector<int> > dp_allbag(const vector<Bag>& bags,int limitWeight)
{
    //2D vector dp[i][j]:背包容量为j,前i个物品的最佳组合价值
    int m=bags.size()+1;
    int n=limitWeight+1;
    vector<vector<int> > dp(m,vector<int>(n,0));

    //init
    
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(j<bags[i-1]._weight)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-bags[i-1]._weight]+bags[i-1]._value);
        }
    }

    /*   
    //we need best bags and nums
    vector<int> res(m-1,0);
    int i=m-1;//包的种类
    int j=n-1;//
    while(i)
    {
        if(dp[i][j] == (dp[i][j-bags[i-1]._weight]+bags[i-1]._value))
        {
            res[i-1]++;
            j = j-bags[i-1]._weight;
        }
        i--;
    }


    // if(a[1][j])//res[0]计算
    // {
    //     res[0] = 1;
    // }

    for(int ii=0;ii<res.size();ii++)
        cout<<res[ii]<<" ";
    cout<<endl;
    */
    return dp;
}

vector<vector<int> > dp_multibag(const vector<Bag>& bags,int limitWeight,const vector<int>& bags_num)
{
    //2D vector dp[i][j]:背包容量为j,前i个物品的最佳组合价值
    int m=bags.size()+1;
    int n=limitWeight+1;
    vector<vector<int> > dp(m,vector<int>(n,0));

    //init
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(j<bags[i-1]._weight)
                dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=dp[i-1][j];
                int count=min(bags_num[i-1],j/bags[i-1]._weight);//计算k的最大次数
                for(int k=1;k<=count;k++)
                {
                    int temp=dp[i-1][j-k*bags[i-1]._weight]+k*bags[i-1]._value;
                    if(temp>dp[i][j])
                        dp[i][j]=temp;
                }
            }
        }
    }
    //we need best bags and nums
    vector<int> res(m-1,0);
    int i=m-1;//包的种类
    int j=n-1;//
    while(i)
    {
        int count=min(bags_num[i-1],j/bags[i-1]._weight);//计算k的最大次数
        for(int k = count; k > 0; k--)
        {
            if(dp[i][j] == (dp[i-1][j-k*bags[i-1]._weight]+k*bags[i-1]._value))
            {
                res[i-1] = k;
                j = j-k*bags[i-1]._weight;
                break;
            }
        }
        i--;
    }

    for(int ii=0;ii<res.size();ii++)
        cout<<res[ii]<<" ";
    cout<<endl;

    return dp;
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

            cols-=bags[i-1]._weight;
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
    int maxlen=0;
    int maxend=0;
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
        {
            if(s1[i-1]==s2[j-1])
                a[i][j]=a[i-1][j-1]+1;
            else
            ;

            if(a[i][j]>maxlen)
            {
                maxlen=a[i][j];
                maxend=i;
            }
        }
        //s1.substr(maxend-maxlen+1,maxlen);
    return a[m-1][n-1];
}

//longest palindrome subsequence,LPS

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

//更加清晰一点
int max_subarray2(const vector<int>& v)
{
    //1D array
    int n=v.size();
    vector<int> dp(n,0);
    dp[0]=v[0];

    for(int i=1;i<n;i++)
    {
        dp[i]=max(dp[i-1]+v[i],v[i]);//以v[i]结尾的最大子数组和
    }

    sort(dp.begin(),dp.end());
    return dp[dp.size()-1];    
}

//乘积数组
vector<int> multiply(const vector<int>& A)
{
    //定义左边右边两个数组
    const int n=A.size();
    vector<int> left(n,0);
    vector<int> right(n,0);
    vector<int> res(n,0);

    //left[0]=1;
    left[0]=1;
    for(int i=1;i<n;i++)
        left[i]=left[i-1]*A[i-1];

    //right[n-1]=1
    right[n-1]=1;
    for(int i=n-2;i>=0;i++)
        right[i]=right[i+1]*A[i+1];

    for(int i=0;i<n;i++)
        res[i]=left[i]*right[i];
    
    return res;
}

//最长递增子序列
//a[i]=max{a[i-1]},if a[i]<=a[j],j=0,,,i-1
//a[i]=max{a[i-1]}+1,if a[i]>a[j]


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
/*优先选择大面值 */

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
/*把速度最慢的两人带过去有两种方法 */
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
//32104
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
    int cur_len=data[0];//当前能够到达的距离
    int pre_len=data[0];//能够跳的最远距离

    for(int i=1;i<data.size();i++)
    {
        if(i>cur_len)//i,cur过程中要跳一次
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
//178543
//17543
//1543
//143
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
        for(int j=0;j<n-i;j++)//前n-i最小
        {
            if(data[j]<data[j+1])
                continue;
            else
            {
                data[j]='a';
                break;
            }
        }

        for(int j=0;j<n-i;j++)//把a移动到最后
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

/***************************************************************************/
/*DFS回溯法*/
/***************************************************************************/
//已知一个数为C，一个长度为n的无序的数组，分别是数w1,w2,...,wn，能否从这n个数中找到若干个数使其和等于数C,要求找出所有满足上述条件的解
//组合数
//数组，目标数，开始索引，临时数组，输出结果
void dfs1(vector<int>& data,int target,int start,vector<int>& temp,vector<vector<int> >& res)
{
    if(target<0)
        return;
    else if(target==0)
    {
        res.push_back(temp);
        for(int i=0;i<temp.size();i++)
            cout<<temp[i];
        cout<<endl;
        return;
    }
    else
    {
        for(int i=start;i<data.size();i++)
        {
            if(i>start&&data[i]==data[i-1]) //去掉重复
                continue;
            temp.push_back(data[i]);
            dfs1(data,target-data[i],i+1,temp,res);//若无限制次数则i+1->i
            temp.pop_back();
        }
    }
}

vector<vector<int> > CombSum(vector<int>& data,int target)
{
    vector<vector<int> > res;
    if(data.empty())
        return res;
    
    vector<int> temp;
    sort(data.begin(),data.end());
    dfs1(data,target,0,temp,res);
    return res;
}

//字符串的全排列
void swap(char& a,char& b)
{
    char temp;
    temp=a;
    a=b;
    b=temp;
}

void dfs2(string str,int start,vector<string> &res)
{
    //退出条件
    if(start==str.size()-1)
    {
        if(find(res.begin(),res.end(),str)==res.end())
            res.push_back(str);
    }
    else
    {
        for(int i=start;i<str.size();i++)
        {
            swap(str[start],str[i]);
            dfs2(str,i+1,res);
            swap(str[start],str[i]);
        }
    } 
}

vector<string> Permutation(string str)
{
    vector<string> res;
    if(str.empty())
        return res;
    
    dfs2(str,0,res);
    sort(res.begin(),res.end());
    return res;
}

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

//01数组最大岛的面积
int max_land01(vector<vector<int> > data)
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
                res=max(res,dfs3(data,i,j));
            }   
        }
    }
    return res;
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

//矩阵中的路径
bool dfs(vector<vector<char> > &data,string s,int u,int x,int y)
{
    //1.退出条件
    if(data[x][y]!=s[u])
        return false;
    if(u==s.size()-1)
        return true;
    
    char t=data[x][y];
    data[x][y]='*';
    //尝试向左
    if(x-1>=0&&dfs(data,s,u+1,x-1,y))
        return true;
    //尝试向右
    if(x+1<data.size()&&dfs(data,s,u+1,x+1,y))
        return true;
    //尝试向上
    if(y-1>=0&&dfs(data,s,u+1,x,y-1))
        return true;
    //尝试向下
    if(y+1<data[0].size()&&dfs(data,s,u+1,x,y+1))
        return true;
        
    data[x][y]=t;
    return false;
}

bool hasPath(vector<vector<char> > &data,string s)
{
    for(int i=0;i<data.size();i++)
    {
        for(int j=0;j<data[0].size();j++)
        {
            if(dfs(data,s,0,i,j))
                return true;
        }
    }
    return false;
}

#endif