#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(int argc,char* argv[])
{
    
    //读数据
    string a;
    string b;
    cin >> a >> b;

    string res="";

    long long aLen=a.size();
    long long bLen=b.size();
    long long maxLen=0;

    if(aLen>bLen)
        maxLen=aLen;
    else
        maxLen=bLen;


    long long* aArr=new long long[maxLen];
    long long* bArr=new long long[maxLen];
    long long* sumArr=new long long[maxLen];

    for(long long i=maxLen-1;i>=0;i--)
    {
        if(aLen<=0)
        {
            aLen=0;
            aArr[i]=0;
        }else
        {
            aArr[i]=a[--aLen]-'0';
        }
    }

    for(long long j=maxLen-1;j>=0;j--)
    {
        if(bLen<=0)
        {
            bArr[j]=0;
        }else
        {
        bArr[j]=b[--bLen]-'0';
        }
    }

    long long jin=0;
    for(long long k=maxLen-1;k>=0;k--)
    {
        sumArr[k]=(aArr[k]+bArr[k]+jin)%10;
        jin=(aArr[k]+bArr[k]+jin)/10;
    }

    if(jin!=0)
        res+="1";
    for(long long t=0;t<maxLen;t++)
        res+= to_string(sumArr[t]);

    cout << res <<endl;

    return 0;
}
