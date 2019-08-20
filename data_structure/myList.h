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

//链表排序，普通排序
template<typename T>
void normalSort(ListNode<T>* root)
{
    ListNode<T>* p;
    ListNode<T>* q;
    for(p=root;p;p=p->next)
    {
        for(q=p->next;q;q=q->next)
        {
            if(p->val>q->val)
            {
                T temp;
                temp=p->val;
                p->val=q->val;
                q->val=temp;
            }
        }
    }
}

//链表排序，选择排序

template<typename T>
void swap(ListNode<T>* p,ListNode<T>* q)
{
    T temp;
    temp=p->val;
    p->val=q->val;
    q->val=temp;
}

template<typename T>
void selectSort(ListNode<T>* root)
{
    ListNode<T>* p;
    ListNode<T>* q;
    ListNode<T>* min;
    for(p=root;p;p=p->next)
    {
        min=p;
        for(q=p->next;q;q=q->next)
        {
            if(min->val>q->val)
            {
                min=q;
            }
        }
        swap(p,min);
    }
}

//链表排序，快速排序
template<typename T>
ListNode<T>* partion(ListNode<T>* begin,ListNode<T>* end)
{
    ListNode<T>* p=begin;
    ListNode<T>* q=begin->next;
    T key=begin->val;

    while(q!=end)//使得p之前的值小于key,pq之间的值都大于key
    {
        if(q->val<key)
        {
            p=p->next;
            swap(p,q);
        }
        q=q->next;
    }
    swap(p,begin);
    return p;
}

template<typename T>
void quickSortLinkList(ListNode<T>* begin, ListNode<T>* end)
{
    if(begin==end)
        return;

    ListNode<T>* temp=partion(begin,end);
    quickSortLinkList(begin,temp);
    quickSortLinkList(temp->next,end);    
}

//链表环
//快慢指针法
template<typename T>
ListNode<T>* isCircle(ListNode<T>* root)
{
    ListNode<T>* slow=root;
    ListNode<T>* fast=root;
    while(slow!=NULL&&fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return slow;
    }
    return NULL;
}

//环的长度
template<typename T>
int getCircleLength(ListNode<T>* meetNode)
{
    int count=0;
    ListNode<T>* temp=meetNode->next;
    while(temp!=meetNode)
    {
       count++;
       temp=temp->next;
    }
    return count;
}

//环的入口点
template<typename T>
ListNode<T>* getCircleNode(ListNode<T>* root)
{
    ListNode<T>* slow=root;
    ListNode<T>* fast=root;
    while(slow!=NULL&&fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }

    slow=root;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

//两链表的公共结点
//1.找长度差k;2.长链表走k后,短链表一起走

template<typename T>
ListNode<T>* findFirstCommonNode(ListNode<T>* root1,ListNode<T>* root2)
{
    ListNode<T>* p1=root1;
    ListNode<T>* p2=root2;

    //计算长度
    int len1=0;
    int len2=0;
    while(p1!=NULL)
    {
        len1++;
        p1=p1->next;
    }
    while(p2!=NULL)
    {
        len2++;
        p2=p2->next;
    }

    //追到等长
    p1=root1;
    p2=root2;
    if(len2>len1)
    {
        for(int i=0;i<(len2-len1);i++)
            p2=p2->next;
    }
    else
    {
        for(int i=0;i<(len2-len1);i++)
            p1=p1->next;
    }
    
    //一起走
    while(p1!=NULL)
    {
        if(p1->val==p2->val)
            return p1;
        else
        {
            p1=p1->next;
            p2=p2->next;
        }
    }

    return NULL;
}

//删除链表的重复结点
//新建头结点法
template<typename T>
ListNode<T>* deleteDuplication(ListNode<T>* pHead)
{
    ListNode<T>* head= new ListNode<T>(0);

    ListNode<T> p=head;
    ListNode<T> q=pHead;

    while(q!=NULL)
    {
        while(q!=NULL&&q->next!=NULL&&q->val==q->next->val)//112233445
        {
            int temp=q->val;
            while(q!=NULL&&q->val==temp)
                q=q->next;
        }

        p->next=q;
        p=p->next;

        if(q)
            q=q->next;
    }
    return head->next;
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