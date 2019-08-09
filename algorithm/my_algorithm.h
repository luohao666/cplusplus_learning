#ifndef __MY_ALGORIHTM_H__
#define __MY_ALGORIHTM_H__

#include<iostream>
#include<vector>
#include<array>

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


#endif