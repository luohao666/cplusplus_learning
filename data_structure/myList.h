#ifndef __MYLIST_H__
#define __MYLIST_H__

#include <list>
#include <iostream>
using namespace std;

template<typename T>
struct ListNode
{
    ListNode(T x):val(x),next(NULL){}
    ListNode* next;
    T val;
};

//链表反转
template<typename T>
ListNode<T>* inverse(ListNode<T>* root)
{
    if(!root)
        return NULL;

    ListNode<T>* newL=NULL;
    ListNode<T>* oldL=root;
    ListNode<T>* temp;
    while(oldL)
    {
        //取出旧表头
        temp=oldL;
        oldL=oldL->next;

        //存入新表头
        temp->next=newL;
        newL=temp;
    }   
    return newL; 
}

//链表合并
template<typename T>
ListNode<T>* merge(ListNode<T>* root1,ListNode<T>* root2)
{
    ListNode<T>* res=NULL;
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

template<typename T>
ListNode<T>* merge2(ListNode<T>* root1,ListNode<T>* root2)
{
    if(!root1)
        return root2;
    if(!root2)
        return root1;

    ListNode<T> *res=NULL;
    ListNode<T> *cur=NULL;

    while(root1!=NULL&&root2!=NULL)
    {
        if(root1->val<=root2->val)
        {
            if(!cur)
            {
                res=cur=root1;
                root1=root1->next;
            }
            else
            {
                cur->next=root1;
                cur=root1;
                root1=root1->next;
            }
        }
        else
        {
            if(!cur)
            {
                res=cur=root2;
                root2=root2->next;
            }
            else
            {
                cur->next=root2;
                cur=root2;
                root2=root2->next;
            }
        }
    }

    if(!root1)
    {
        cur->next=root2;
    }
    if(!root2)
    {
        cur->next=root1;
    }
    return res;
}

//倒数第k个节点
template<typename T>
ListNode<T>* FindKthToTail(ListNode<T>* root,int k)
{
    ListNode<T>* temp=root;
    int count=0;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    if(k>count)
        return NULL;

    ListNode<T>* temp2=root;
    for(int i=0;i<k;i++)
    {
        temp2=temp2->next;
    }

    ListNode<T>* res=root;
    while(temp2)
    {
        temp2=temp2->next;
        res=res->next;
    }
    return res;
}

template<typename T>
void print(ListNode<T>* root)
{
    ListNode<T>* cur=root;
    while(cur)
    {
        cout<<cur->val;
        cur=cur->next;
    }
    cout<<endl;
}
#endif