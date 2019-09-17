#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

//活动选择问题
struct Bag
{
    Bag(int x,int h):_x(x),_h(h){}
    int _x;
    int _h;
};

bool cmp(const Bag& b1,const Bag& b2)
{
    int t1=max(b1._x,b1._h);
    int t2=max(b2._x,b2._h);
    return t1<t2;
}

int main(int argc,char* argv[])
{

    int n;
    cin >> n;
    vector<Bag> data;

    for(int i=0;i<n;i++)
    {
        int tmp1=0;
        int tmp2=0;
        cin >> tmp1 >> tmp2;
        Bag bag(tmp1,tmp2);
        data.push_back(bag);
    }

    sort(data.begin(),data.end(),cmp);

    for(int i=0;i<n;i++)
        cout<<data[i]._x<<" "<<data[i]._h<<endl;

    int count=1;
    int j=1;
    int t_x=data[0]._x;
    int t_h=data[0]._h;
    while(j<n)
    {
        if(data[j]._x<t_x||data[j]._h<t_h||(data[j]._x==t_x&&data[j]._h==t_h))
        {
            t_x=data[j]._x;
            t_h=data[j]._h;
            j++;
        }
        else
        {
            count++;
            t_x=data[j]._x;
            t_h=data[j]._h;
            j++;
        }
    }
    cout<<count<<endl;
    return 0;
}
