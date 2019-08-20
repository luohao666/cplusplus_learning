#ifndef __MY_SEARCH_H__
#define __MY_SEARCH_H__

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
bool binarySearch(const vector<T> data, T a)
{
    //sort(data.begin(),data.end());
    int right=data.size()-1;
    int left=0;
    while(left<=right)
    {
        int mid=(right+left)/2;
        if(a==data[mid])
            return true;
        else if(a>data[mid])//说明a在右区间
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return false;
}

//minv_rotate_array
int helper(const vector<int>& data,int left,int right)
{
    int res=data[left];
    for(int i=left;i<=right;i++)
    {
      //  cout<<data[i]<<endl;
        if(data[i]<res)
            res=data[i];
    }
    return res;
}

int minv_rotate_array(const vector<int>& data)
{
    const int n=data.size();
    int left=0;
    int right=n-1;
    int mid=0;
    while(left<right)
    {
        if(right-left==1)
            return data[right];

        mid=(left+right)/2;
        if(data[left]==data[right]&&data[left]==data[mid])//不能区分
            return helper(data,left,right);

        if(data[mid]<data[left])//在左区间
            right=mid;
        if(data[mid]>=data[left])//在右区间
            left=mid;
    }
    return data[mid];
}

//统计数字在排序数组里出现的次数
int findFirstK(const vector<int>& data,int k)
{
    const int n=data.size();
    int left=0;
    int right=n-1;
    int mid=0;
    while(left<right)
    {
        mid=(left+right)/2;
        if(data[mid]<k)
            left=mid+1;
        else
            right=mid-1;
    }
    return left;
}

int findLastK(const vector<int>& data,int k)
{
    const int n=data.size();
    int left=0;
    int right=n-1;
    int mid=0;
    while(left<right)
    {
        mid=(left+right)/2;
        if(data[mid]<=k)
            left=mid+1;
        else
            right=mid-1;
    }
    return right;
}

int numOfK(const vector<int>& data,int k)
{
    int left=findFirstK(data,k);
    int right=findLastK(data,k);
    return right-left;
}

#endif