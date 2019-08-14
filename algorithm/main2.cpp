#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
/* 
void find_min(const vector<int>& data,vector<int>& vmin,vector<int>& vmax)
{
    int n=data.size();

    for(int i=1;i<n-1;i++)
    {
        if(data[i]<data[i-1]&&data[i]<=data[i+1]||data[i]<=data[i-1]&&data[i]<data[i+1])
            vmin.push_back(i);
        
        if(data[i]>data[i-1]&&data[i]>=data[i+1]||data[i]>=data[i-1]&&data[i]>data[i+1])
            vmax.push_back(i);
    }

    if(data[0]>data[1])
        vmax.push_back(0);
    if(data[0]<data[1])
        vmin.push_back(0);
    if(data[0]==data[1]&&vmin[0]>vmax[0])
        vmax.push_back(0);
    if(data[0]==data[1]&&vmin[0]<vmax[0])
        vmin.push_back(0);

    if(data[n-1]>data[n-2])
        vmax.push_back(n-1);
    if(data[n-1]<data[n-2])
        vmin.push_back(n-1);
    if(data[n-1]==data[n-2]&&vmin[vmin.size()-1]>vmax[vmax.size()-1])
        vmax.push_back(n-1);
    if(data[n-1]==data[n-2]&&vmin[vmin.size()-1]<vmax[vmax.size()-1])
        vmin.push_back(n-1);

}

void distances(const vector<int>& vmin,const vector<int>& vmax,vector<int> dists)
{
    sort(vmin.begin(),vmin.end());
    sort(vmax.begin(),vmax.end());
    int n1=vmin.size();
    int n2=vmax.size();
    int k=0;
    for(int i,j=0;i<n1||j<n2;)
    {
        if(vmin[0]==0)
        {
            if(vmin[i+1]-vmin[i]>vmax[j]-vmin[i])
            {
                dists.push_back(vmax[j]-vmin[i]);
                i++;j++;
            }
            else
            {
                dists.push_back(vmin[i+1]-vmin[i]);
                i++;
            }
            
        }        
        else
        {
            if(vmax[i+1]-vmax[i]>vmin[j]-vmax[i])
            {
                dists.push_back(vmin[j]-vmax[i]);
                i++;j++;
            }
            else
            {
                dists.push_back(vmax[i+1]-vmax[i]);
                j++;
            }
        }
    }
}
*/

int main(int argc,char* argv[])
{
   
//读指定的n个数据
    int n;
    vector<string> data;
    string t;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        data.push_back(t);
    }
    
    return 0;
}
