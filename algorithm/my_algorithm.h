#ifndef __MY_ALGORIHTM_H__
#define __MY_ALGORIHTM_H__

#include<iostream>
#include<vector>
#include<array>
#include<string>

using namespace std;

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

//longestPalindrome

#endif