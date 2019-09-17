#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

bool huiwen(vector<int> data)
{
	int i=0;
	int j=data.size()-1;
	while(i<j)
	{
		if(data[i]!=data[j])
			return false;
		else
		{
			i++;j--;
		}
	}
	return true;
}

int main(int argc,char* argv[])
{
    //读数据
//    cout<<"io test"<<endl;

//读n个数据,ctrl+d中断
    int s;
    vector<int> data;
    while(cin>>s)
    {
        data.push_back(s);
    }
   
	if(huiwen(data))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
	
    return 0;
}
