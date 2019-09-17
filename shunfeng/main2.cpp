#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



int macth_length(string s1,string s2)
{
    int len1=s1.size();
    int len2=s2.size();
    int i=0;
    int j=0;
    int res=0;
    while(i<len1&&j<len2)
    {
        if(s1[i]==s2[j])
        {
            i++;
            j++;
        }
        else
        {
            res=i;break;
        }
    }
    if(i>j)
        res=i;
    else
        res=j;
    return res;
}

int main(int argc,char* argv[])
{
    /* 
    //读n个数据,ctrl+d中断
    string s;
    vector<string> data;
    while(cin>>s)
    {
        data.push_back(s);
    }
    //验证
    //cout<<data.size()<<endl;
    //for(int i=0;i<data.size();i++)
    //    cout<<data[i]<<endl;

*/
    string dataall;
    cin>>dataall;
    vector<string> data;

    for(int i=0;i<dataall.size();i++)
    {
        string t="";
        if(dataall[i]!=',')
            t+=data[i];
        else
            data.push_back(t);
    }
    int n=data.size();
    cout<<n<<endl;

//    string s1="asdf";
//    string s2="asdfh";
//    cout<<macth_length(s1,s2)<<endl;
    vector<string> res(data);
    for(int i=0;i<n;i++)
    {
        int maxlen=0;
        int maxindex=0;
        for(int j=i+1;j<n;j++)
        {
            int len=macth_length(data[i],data[j]);
            if(maxlen<len)
            {
                maxlen=len;
                maxindex=j;
            }
        }
        res[i]=data[i].substr(i,maxlen+1);
        res[maxindex]=data[maxindex].substr(i,maxlen+1);
    }

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }   
    cout<<endl;
    return 0;
}
