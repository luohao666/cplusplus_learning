#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


//longest substring
int ls(string s,int& start,int& end,char& mchar)
{
    int n=s.size();
    char temp=s[0];
    int count=1;
    int max=1;
    int counter=0;

    for(int i=1;i<n;i++)
    {
        if(temp==s[i])
        {
            count++;
        }
        else
        {
            count=1;
        }
        if(count>max)
        {
            max=count;
            end=i;
            start=end-max+1;
            mchar=s[i];
        }

        temp=s[i];
    }
    return max;
}

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

    for(int i=0;i<n;i++)
    {
        string s=data[i];
        int start=0;
        int end=0;
        char mchar;

        ls(s,start,end,mchar);
//cout<<start<<","<<end<<","<<mchar<<endl;

        int score3=0;
        int score4=0;

        if(start>0)
        {
            int score1=0;
            int score2=0;

            string s1=s;
            s1[start-1]=mchar;
            int start2=0;
            int end2=0;
            char mchar2;

            score3=ls(s1,start2,end2,mchar2);

            if(start2>0||end2<s.size()-1)
            {
                //cout<<s1<<endl;
                if(start2>0)
                {
                    string s2=s1;
                    s2[start2-1]=mchar2;
                    score1=ls(s2,start2,end2,mchar2);

    //cout<<s2<<endl;
    //cout<<score1<<endl;

                }

                else if(end2<s.size()-1)
                {
                    string s2=s1;
                    s2[end2+1]=mchar;
                    score2=ls(s2,start2,end2,mchar2);

    //cout<<s2<<endl;
    //cout<<score2<<endl;
                }

                if(score1>=score2)
                    score3=score1;
                else
                    score3=score2;
            }
        }

        if(end<s.size()-1)
        {
//cout<<s<<endl;
            int score1=0;
            int score2=0;

            string s1=s;
            s1[end+1]=mchar;
            int start2=0;
            int end2=0;
            char mchar2;

            score4=ls(s1,start2,end2,mchar2);

//cout<<s1<<endl;
            if(start2>0||end2<s.size()-1)
            {
                if(start2>0)
                {
                    string s2=s1;
                    s2[start2-1]=mchar2;
                    score1=ls(s2,start2,end2,mchar2);
    //cout<<s2<<endl;
    //cout<<score1<<endl;
                }

                if(end2<s.size()-1)
                {
                    string s2=s1;
                    s2[end2+1]=mchar;
                    score2=ls(s2,start2,end2,mchar2);
    //cout<<s2<<endl;
    //cout<<score2<<endl;
                }

                if(score1>=score2)
                    score4=score1;
                else
                    score4=score2;
            }

            if(score4>=score3)
                cout<<score4<<endl;
            else
                cout<<score3<<endl;
            }
            
        }
    
    return 0;
}
