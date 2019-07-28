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
#endif