#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


bool isInside(vector<int>& datas,int d)
{
    vector<int>::iterator it;
    it=find(datas.begin(),datas.end(),d);
    if (it!=datas.end())//如果不是sign里的字符
        return true;
    else
        return false;
}

struct Bag
{
    Bag(int w,int v):_a(w),_b(v){}

    int _a;
    int _b;
};

int main(int argc,char* argv[])
{
    //读数据
//    cout<<"io test"<<endl;

    int n;
    cin >> n;

    if(n<1||n>10e5)
        return -1;

    vector<Bag> bags;
    for(int i=0;i<n;i++)
    {
        int a;
        int b;
        cin >> a >> b;
        Bag bag(a,b);
        bags.push_back(bag);
    }

    int min_sum=0;
    vector<int> datas;

    for(int i=1;i<=n;i++)
    {
        int min=10e8;
        int min_index=0;
        
        //cout<< datas.size() <<endl;

        for(int j=0;j<n;j++)
        {
            if(isInside(datas,j))
                continue;

            int score=(i-1)*bags[j]._a+(n-i)*bags[j]._b;
            if(score<min)
            {
                min=score;
                min_index=j;
            }
        }
        datas.push_back(min_index);
        min_sum+=min;
    }

    cout<< min_sum<<endl;

    return 0;
}
