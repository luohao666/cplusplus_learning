#ifndef __MY_H__
#define __MY_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

//约瑟夫环
int lastRemain1(int n,int m)
{
    if(m==0&&n==0)
        return -1;

    list<int> l;
    for(int i=0;i<n;i++)
        l.push_back(i);
    
    list<int>::iterator iter=l.begin();
    int count=0;
    while(l.size()>1)
    {   
        for(int i=0;i<m;i++)
        {
            iter++;
            if(iter==l.end())
                iter=l.begin();
        }

        //记录下一个元素
        list<int>::iterator next=++iter;
        if(next==l.end())
            next=l.begin();
        
        iter--;
        l.erase(iter);
        iter=next;
    }
    return l.front();
}

int lastRemain2(int n,int m)
{
    if(m==0&&n==0)
        return -1;

    queue<int> q;
    for(int i=0;i<n;i++)
        q.push(i);
    
    int count=0;
    while(q.size()>1)
    {
        int temp=q.front();
        q.pop();

        if(count==m-1)
            count=-1;
        else
            q.push(temp);
        count++;
    }
    return q.front();
}

class Singleton
{
    public:
        static Singleton& get_instance()
        {
            static Singleton singleton;
            return singleton;
        }

        void show()
        {
            cout<<"hello singleton!"<<endl;
        } 
        
    private:
        Singleton(){};
};

/************************************************ */
/* 双指针方法*/
/************************************************ */

//数组里奇数在偶数前面
bool isEven(int data)
{
    if(data%2==0)
        return true;
    else
        return false;
}

void reOrderArray(vector<int> &data)
{
    const int n=data.size();
    int i=0;//第一个偶数
    int j=0;//第一个奇数

    while(i<n)
    {
        while(i<n&&!isEven(data[i]))
            i++;
        j=i+1;
        while(j<n&&isEven(data[j]))
            j++;
        
        if(j<n)
        {
            int temp=data[j];
            for(int k=j;k>i;k--)//右移动一个单位
                data[k]=data[k-1];
            data[i]=temp;
        }
        else
        {
            break;
        }
    }
}

//递增数组和为s的两个数字
vector<int> FindNumbersWithSum(const vector<int>& data,int s)
{
    vector<int> res;
    const int n=data.size();
    if(n<=0)
        return res;
    
    int left=0;
    int right=n-1;

    while(left<right)
    {
        if(data[left]+data[right]==s)
        {
            res.push_back(data[left]);
            res.push_back(data[right]);
        }
        while(left<right&&data[left]+data[right]>s)
            right--;

        while(left<right&&data[left]+data[right]<s)
            left++;
    }
    return res;
}

//连续正数和为s
vector<vector<int> > findContinuousSequence(int sum)
{
    vector<vector<int> > res;
    if(sum<3)
    return res;

    int left=0;
    int right=left+1;

    while(left<right)
    {
        int cur=(left+right)*(right-left+1)/2;
        if(cur==sum)
        {
            vector<int> temp;
            for(int i=left;i<=right;i++)
                temp.push_back(i);
            res.push_back(temp);    
        }

        if(cur<sum)
            right++;
        if(cur>sum)
            right--;
    }
    return res;
}

/************************************************ */
/* 栈基本用法*/
/************************************************ */

//栈的队列实现
namespace STACK{
    stack<int> s1;
    stack<int> s2;

    void push(int a)
    {
        s1.push(a);
    }

    void pop()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int temp=s1.top();s1.pop();
                s2.push(temp);
            }
        }
        s2.pop();
    }
}

//最小元素栈
namespace MINSTACK{
    stack<int> dataStack;
    stack<int> minStack;

    void push(int value)
    {
        dataStack.push(value);
        if(minStack.empty())
            minStack.push(value);
        else
        {
            if(value<minStack.top())
                minStack.push(value);   
        }
    }

    void pop()
    {
        if(dataStack.top()==minStack.top())
        {
            dataStack.pop();
            minStack.pop();
        }
    }

    int top()
    {
        dataStack.top();
    }

    int min()
    {
        return minStack.top();
    }
}

//栈的压入弹出序列
//思路：构造一个辅助栈，如果栈顶元素不是弹出元素，入栈；
//如果栈顶元素等于入栈元素，出栈
//如果最后辅助栈为空，则为弹出序列
bool IsPopOrder(vector<int> pushV,vector<int> popV)
{
    if(pushV.size()!=popV.size())
        return false;
    
    stack<int> s;
    for(int i=0,j=0;i<pushV.size();i++)
    {
        s.push(pushV[i]);
        while(!s.empty()&&s.top()==popV[j])
        {
            s.pop();
            j++;
        }
    }
    return s.empty();
}

/************************************************ */
/* topK */
/************************************************ */

//分治法
int parttion(vector<int> data,int left,int right)
{
    int temp=data[left];
    while(left<right)
    {
        while(left<right&&data[right]>temp)
            right--;
        data[left]=data[right];
        while(left<right&&data[left]<temp)
            left++;
        data[right]=data[left];
    }
    data[left]=temp;
    return left;
}

vector<int> topK(vector<int> data,int k)
{
    if(k>data.size())
        return vector<int> ();

    if(k==data.size())
        return data;

    int len=data.size();
    int temp=parttion(data,0,len-1);

    while(temp!=k-1)
    {
        if(temp>k-1)
        {
            temp=parttion(data,0,temp-1);
        }
        else
        {   
            temp=parttion(data,temp+1,len-1);
        }
    }

    vector<int> res(data.begin(),data.begin()+k);
    return res;
}

//堆排序方法

//堆排序

#endif