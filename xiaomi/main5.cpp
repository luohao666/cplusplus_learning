#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

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

    int t;//组数
    int k;//倍数基
    cin >> t >> k;

    vector<Bag> bags;
    for(int i=0;i<t;i++)
    {
        int a;
        int b;
        cin >> a >> b;
        Bag bag(a,b);
        bags.push_back(bag);
    }

    int nums=0;
    for(int i=0;i<t;i++)
    {
        int a=bags[i]._a;
        int b=bags[i]._b;

        int max_times=b/k;
        for(int j=0;j<=max_times;j++)
        {
            int start=0;
            if(j*k>a)
                start=j*k;
            else
                start=a;
                
            for(int jj=start;j<=b;jj++)
            {
                int fenzi=1;
                int fenmu=1;
                int down=jj;
                int up=start;
                for(int index=0;index<start;index++)
                {
                    fenzi*=down;
                    down--;
                    fenmu*=up;
                    up--;
                }
                nums+=fenzi/fenmu;
            }
        }
    }
       cout<<nums<<endl; 
    return 0;
}
