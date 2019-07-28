#ifndef __MYSORT_H__
#define __MYSORT_H_

#include <iostream>
#include <ctime>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>


using namespace std;

void using_set()
{
    const int N=6;
    int a[N]={5,4,3,2,1,1};
    for(int i=0;i<N;i++)
        cout<<a[i];
    cout<<endl;

    set<int> s(a,a+6);
    set<int>::iterator iter;
    for(iter=s.begin();iter!=s.end();++iter)
        cout<<*iter;
    cout<<endl;

    set<int>::iterator iter2 = s.find(5);
    if(iter2!=s.end())
        cout<<*iter2<<endl;
}

void using_multiset()
{
    const int N=6;
    int a[N]={5,4,3,2,1,1};
    for(int i=0;i<N;i++)
        cout<<a[i];
    cout<<endl;

    multiset<int> s(a,a+6);
    multiset<int>::iterator iter;
    for(iter=s.begin();iter!=s.end();++iter)
        cout<<*iter;
    cout<<endl;

    multiset<int>::iterator iter2 = s.find(5);
    if(iter2!=s.end())
        cout<<*iter2<<endl;
}

void using_map()
{
    const int N=6;
    int a[N]={5,4,3,2,1,1};
    float b[N]={55,44,33,22,11,11};
    for(int i=0;i<N;i++)
        cout<<a[i];
    cout<<endl;
    for(int i=0;i<N;i++)
        cout<<b[i];
    cout<<endl;
    clock_t t1=clock();
    map<int,float> m;//m对key进行排序
    for(int i=0;i<10000;i++)
    {
        m[a[i%N]]=b[i%N];
    }
    clock_t t2=clock();
    cout <<"time use in normal inverse is " << 1000* (t2 - t1)/(double)CLOCKS_PER_SEC << "ms"<< endl;

    map<int,float>::iterator iter;

    for(iter=m.begin();iter!=m.end();++iter)
        cout<<iter->first;
    cout<<endl;
    for(iter=m.begin();iter!=m.end();++iter)
        cout<<iter->second;
    cout<<endl;

    map<int,float>::iterator iter2 = m.find(5);
    if(iter2!=m.end())
    {
        cout<<iter2->first<<endl;
        cout<<iter2->second<<endl;
    }

}

void using_multimap()
{
    const int N=6;
    int a[N]={5,4,3,2,1,1};
    float b[N]={55,44,33,22,11,11};
    for(int i=0;i<N;i++)
        cout<<a[i];
    cout<<endl;
    for(int i=0;i<N;i++)
        cout<<b[i];
    cout<<endl;
    multimap<int,float> m;//m对key进行排序
    for(int i=0;i<N;i++)
    {
        m.insert(make_pair(a[i],b[i]));
    }
    /* 
    for(int i=0;i<N;i++)
    {
        m[a[i]]=b[i];
    }
    */
    multimap<int,float>::iterator iter;

    for(iter=m.begin();iter!=m.end();++iter)
        cout<<iter->first;
    cout<<endl;
    for(iter=m.begin();iter!=m.end();++iter)
        cout<<iter->second;
    cout<<endl;

    multimap<int,float>::iterator iter2 = m.find(5);
    if(iter2!=m.end())
    {
        cout<<iter2->first<<endl;
        cout<<iter2->second<<endl;
    }

}

void using_unordered_set()
{
    const int N=6;
    int a[N]={5,4,3,2,1,1};
    for(int i=0;i<N;i++)
        cout<<a[i];
    cout<<endl;

    unordered_set<int> s(a,a+6);
    unordered_set<int>::iterator iter;
    for(iter=s.begin();iter!=s.end();++iter)
        cout<<*iter;
    cout<<endl;
}

void using_unordered_multiset()
{
    const int N=6;
    int a[N]={5,4,3,2,1,1};
    for(int i=0;i<N;i++)
        cout<<a[i];
    cout<<endl;

    unordered_multiset<int> s(a,a+6);
    unordered_multiset<int>::iterator iter;
    for(iter=s.begin();iter!=s.end();++iter)
        cout<<*iter;
    cout<<endl;
}

void using_unordered_map()
{
    const int N=6;
    int a[N]={5,4,3,2,1,1};
    float b[N]={55,44,33,22,11,11};
    for(int i=0;i<N;i++)
        cout<<a[i];
    cout<<endl;
    for(int i=0;i<N;i++)
        cout<<b[i];
    cout<<endl;
    unordered_map<int,float> m;//m对key进行排序
    for(int i=0;i<N;i++)
    {
        m[a[i]]=b[i];
    }
    unordered_map<int,float>::iterator iter;

    for(iter=m.begin();iter!=m.end();++iter)
        cout<<iter->first;
    cout<<endl;
    for(iter=m.begin();iter!=m.end();++iter)
        cout<<iter->second;
    cout<<endl;

}

void using_unordered_multimap()
{
    const int N=6;
    int a[N]={5,4,3,2,1,1};
    float b[N]={55,44,33,22,11,11};
    for(int i=0;i<N;i++)
        cout<<a[i];
    cout<<endl;
    for(int i=0;i<N;i++)
        cout<<b[i];
    cout<<endl;
    unordered_multimap<int,float> m;//m对key进行排序
    for(int i=0;i<N;i++)
    {
        m.insert(make_pair(a[i],b[i]));
    }
    /* 
    for(int i=0;i<N;i++)
    {
        m[a[i]]=b[i];
    }
    */
    unordered_multimap<int,float>::iterator iter;

    for(iter=m.begin();iter!=m.end();++iter)
        cout<<iter->first;
    cout<<endl;
    for(iter=m.begin();iter!=m.end();++iter)
        cout<<iter->second;
    cout<<endl;

}

#endif
