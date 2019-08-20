#ifndef __MYSORT_H__
#define __MYSORT_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class mysort
{
    public:
        template<typename T>
        static void normalSort(vector<T>& data);
        template<typename T>
        static void selectSort(vector<T>& data);
        template<typename T>
        static void bubbleSort(vector<T>& data);
        template<typename T>
        static void bubbleSort2(vector<T>& data);
        template<typename T>
        static void print(const vector<T>& data);

};

template<typename T>
void mysort::print(const vector<T>& data)
{
    const int N=data.size();
    for(int i=0;i<N;i++)
        cout<< data[i]<<endl;
}

template<typename T>
void mysort::normalSort(vector<T>& data)
{
    const int N=data.size();
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
        {
            if(data[i]>data[j])
            {
                T temp;
                temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }
}

template<typename T>
void mysort::selectSort(vector<T>& data)
{
    const int N=data.size();
    for(int i=0;i<N;i++)
    {
        int min=i;
        for(int j=i+1;j<N;j++)
        {
            if(data[min]>data[j])
            {
                min=j;
            }
        }
        T temp;
        temp=data[i];
        data[i]=data[min];
        data[min]=temp;
    }
}

template<typename T>
void mysort::bubbleSort(vector<T>& data)
{
    const int N=data.size();
    for(int i=0;i<N;i++)
        for(int j=0;j<N-i;j++)
        {
            if(data[j]>data[j+1])
            {
                T temp;
                temp=data[i];
                data[i]=data[j];
                data[j]=temp;
            }
        }
}

template<typename T>
void mysort::bubbleSort2(vector<T>& data)
{
    const int N=data.size();
    bool flag=true;
    for(int i=0;i<N&&flag;i++)
    {
        flag=false;
        for(int j=0;j<N-i;j++)
        {
            if(data[j]>data[j+1])
            {
                flag=true;
                T temp;
                temp=data[j];
                data[j+1]=temp;
                data[j]=temp;
            }
        }
    }
}

template<typename T>
int partion(vector<T>& data,int start,int end)
{
    T temp=data[start];
    while(start<end)
    {
        while(start<end&&data[end]>temp)//right
            end--;
        data[start]=data[end];
        while(start<end&&data[start]<temp)//left
            start++;
        data[end]=data[start];
    }
    data[start]=temp;
    return start;
}

template<typename T>
void quickSort(vector<T>& data,int start,int end)
{
    if(start>=end)
        return;
    int t=partion(data,start,end);
    quickSort(data,start,t-1);
    quickSort(data,t+1,end);
}

template<typename T>
void quickSort2(vector<T>& data,int start,int end)
{
    if(start>end)
        return;
    
    stack<T> s;
    s.push(end);//先存右指针
    s.push(start);//再存左指针
    
    while(!s.empty())
    {
        int left=s.top();s.pop();//先取左指针
        int right=s.top();s.pop();//再取右指针

        int t=partion(data,left,right);
        
        if(t>left)
        {
            s.push(t-1);//先存右指针
            s.push(left);
        }
        if(t<right)
        {
            s.push(right);
            s.push(t+1);
        }
    }

}

template<typename T>
void mergeSort(vector<T> &data,int start,int end,vector<T> &copy)
{
    if(start==end)
    {
        copy[start]=data[start];
        return;
    }
    
    int mid=(start+end)/2;
    mergeSort(data,start,mid,copy);
    mergeSort(data,mid+1,end,copy);

    //三个数组尾指针
    int i=mid;//left
    int j=end;//right
    int k=end;//copy

    while(i>=start&&j>=mid+1)
    {
        if(data[i]>data[j])
            copy[k--]=data[i--];
        else
            copy[k--]=data[j--];
    }
    
    //把没有来得及比的补上
    for(;i>=start;--i)
        copy[k--]=data[i];
    for(;j>=mid+1;--j)
        copy[k--]=data[j];

    //排序
    for(int i=start;i<=end;i++)
    {
        data[i]=copy[i];
    }
}

//堆排序

#endif