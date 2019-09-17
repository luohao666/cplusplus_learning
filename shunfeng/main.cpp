#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


struct Bag
{
    Bag(char w,int v):_sign(w),_score(v){}

    char _sign;
    int _score;
};

bool cmp(Bag b1,Bag b2)
{
    return b1._score>b2._score;
}

int main(int argc,char* argv[])
{
    //读数据
    int n;
    string tihao;
    vector<int> defen;
    cin >> n;
    cin >> tihao;
    for(int i=0;i<13;i++)
    {
        int temp;
        cin>>temp;
        defen.push_back(temp);
    }

    if(n!=tihao.length())
        return -1;
/* 
    //debug
    cout<<n<<endl;
    cout<<tihao<<endl;
    for(int i=0;i<13;i++)
    {
        cout<<defen[i]<<" ";
    }
    cout<<endl;
*/

    string s="ABCDEFGHIJKLM";
    vector<Bag> bags;
    for(int i=0;i<13;i++)
    {
        Bag b(s[i],defen[i]);
        bags.push_back(b);
    }

/* 
    //debug
    for(int i=0;i<bags.size();i++)
    {
        cout<<bags[i]._sign<<bags[i]._score<<" ";
    }
    cout<<endl;
*/

    for(int i=0,j=0;i<13&&j<n;i++)
    {
        if(bags[i]._sign==tihao[j])
        {
 //           cout<<bags[i]._sign<<endl;
            bags.erase(bags.begin()+i);
            j++;
            i=0;
        }
    }

 /*    
        //debug
    for(int i=0;i<bags.size();i++)
    {
        cout<<bags[i]._sign<<bags[i]._score<<" ";
    }
    cout<<endl;
*/

    sort(bags.begin(),bags.end(),cmp);

    if(bags[0]._score==bags[1]._score)
    {
        if(bags[0]._sign<bags[1]._sign)
            cout<<bags[0]._sign<<endl;
        else
            cout<<bags[1]._sign<<endl;
    }
    else
        cout<<bags[0]._sign<<endl;

    return 0;
}

