#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int find(const vector<int>& data)
{
    int size=data.size();
    if(size<3)
        return -1;
    
    for(int i=1;i<size-1;i++)
    {
        if(data[i]>data[i-1]&&data[i]>data[i+1])
            return i;
    }
}


void func(vector<vector<int> >& data)
{
    int rows=data.size();
    int cols=data.size();
    vector<vector<bool> > flag(rows,vector<bool>(cols,false));
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(data[i][j]==0&&flag[i][j]==false)
            {
                flag[i][j]=true;
            }
        }
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(flag[i][j]==true)
            {
                for(int k=0;k<cols;k++)
                    data[i][k]=0;
                for(int k=0;k<rows;k++)
                    data[k][j]=0;
            }
        }
    }
}

struct ListNode
{
    ListNode(int x):val(x),next(NULL){}
    ListNode* next;
    int val;
};

//链表合并
ListNode* merge(ListNode* root1,ListNode* root2)
{
    ListNode* res=NULL;

    //确定递归终止条件
    if(!root1)
        return root2;
    if(!root2)
        return root1;

    if(root1->val<=root2->val)
    {
        res=root1;
        res->next=merge(root1->next,root2);
    }
    else
    {
        res=root2;
        res->next=merge(root1,root2->next);
    }
    return res;
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    const int n=lists.size();
    if(n<=1)
        return lists[0];

    ListNode* root1=lists[0];
    for(int i=1;i<n;i++)
    {
        ListNode* root2=lists[i];
        root1=merge(root1,root2);
    }
    return root1;
}

int main(int argc,char* argv[])
{
    
//    int index=find(data);

    return 0;
}
