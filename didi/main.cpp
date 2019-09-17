#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


template<typename T>
int partion(vector<T>& data,int start,int end)
{
    T temp=data[start];
    while(start<end)
    {
        while(start<end&&data[end]>temp)//right
            end--;
        data[start]=data[end];
        while(start<end&&data[start]<temp)//left
            start++;
        data[end]=data[start];
    }
    data[start]=temp;
    return start;
}

template<typename T>
void quickSort(vector<T>& data,int start,int end)
{
    if(start>=end)
        return;
    int t=partion(data,start,end);
    quickSort(data,start,t-1);
    quickSort(data,t+1,end);
}

//如果连加或连加，sort


void func(vector<int>& shuzi,vector<char> fuhao)
{
    //双指针寻找连乘或者连加
    int i=0;
    int j=0;
    while(i<fuhao.size())
    {
        if(fuhao[i]=='*')
        {        
            j=i;
            while(fuhao[j]=='*')
                j++;
            quickSort(shuzi,i,j);
            i=j;
        }
        else 
            i++;
    }
    
    i=0;
    j=0;
    while(i<fuhao.size())
    {
        if(fuhao[i]=='+')
        {        
            j=i;
            while(fuhao[j]=='+')
                j++;
            
            int start=0;
            if(i==0)
                start=0;
            else
                start=i+1;
            
            quickSort(shuzi,start,j);
            i=j;
        }
        else 
            i++;
    }
 
    //验证
    for(int i=0;i<shuzi.size();i++)
    {
        cout<<shuzi[i];
        cout<<fuhao[i];
    }
    cout<<endl;

    
}

int main(int argc,char* argv[])
{
    //读数据
    int n;
    vector<int> shuzi;
    vector<char> fuhao;
    cin >> n;

    for(int i=0;i<2*n-1;i++)
    {
        if(i%2==0)
        {
            int temp;
            cin>>temp;
            shuzi.push_back(temp);
        }
        else
        {
            char temp;
            cin>>temp;
            fuhao.push_back(temp);
        } 
   }
    //验证
//    cout<<n<<endl;
//    cout<<data.length()<<endl;

    func(shuzi,fuhao);



    return 0;
}

