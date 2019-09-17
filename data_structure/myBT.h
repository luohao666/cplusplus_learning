#ifndef __MYBTREE_H__
#define __MYBTREE_H_

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

template<typename T>
struct TreeNode
{
    TreeNode(T x):val(x),left(NULL),right(NULL){}

    TreeNode<T> *left;
    TreeNode<T> *right;
    T val;
};

//pre
template<typename T>
void pre(TreeNode<T> *root)
{
    if(!root)
        return;
    cout<<root->val<<endl;
    pre(root->left);
    pre(root->right);
}

template<typename T>
void pre2(TreeNode<T> *root)
{
    if(!root)
        return;
    stack<TreeNode<T> *> s;
    TreeNode<T> *cur=root;
    while(cur||!s.empty())
    {
        if(cur)
        {
            cout<<cur->val<<endl;
            s.push(cur);
            cur=cur->left;
        }
        else
        {
            cur=s.top();s.pop();
            cur=cur->right;
        }
        
    }
}

//mid
template<typename T>
void mid(TreeNode<T> *root)
{
    if(!root)
        return;
    pre(root->left);
    cout<<root->val<<endl;
    pre(root->right);
}

template<typename T>
void mid2(TreeNode<T> *root)
{
    if(!root)
        return;
    stack<TreeNode<T> *> s;
    TreeNode<T> *cur=root;
    while(cur||!s.empty())
    {
        if(cur)
        {
            s.push(cur);
            cur=cur->left;
        }
        else
        {
            cur=s.top();s.pop();
            cout<<cur->val<<endl;
            cur=cur->right;
        }
    }
}

//post
template<typename T>
void post(TreeNode<T> *root)
{
    if(!root)
        return;

    post(root->left);
    post(root->right);
    cout<<root->val<<endl;
}

template<typename T>
void post2(TreeNode<T> *root)
{
    if(!root)
        return;
    stack<TreeNode<T> *> s1;
    s1.push(root);
    stack<TreeNode<T> *> s2;

    while(!s1.empty())
    {
        TreeNode<T> *cur=s1.top();s1.pop();
        s2.push(cur);

        if(cur->left)
            s1.push(cur->left);
        
        if(cur->right)
            s1.push(cur->right);
    }

    while(!s2.empty())
    {
        cout<<s2.top()->val<<endl;
        s2.pop();
    }
}
/*
struct TreeNode
{
    TreeNode(int x):val(x),left(NULL),right(NULL)
    {

    }

    TreeNode* left;
    TreeNode* right;
    int val;
};

//先序遍历
void pre(TreeNode* root)
{
    if(!root)
        return;
    cout<<root->val<<endl;
    pre(root->left);
    pre(root->right);
}

void pre2(TreeNode* root)
{
    if(!root)
        return;

    stack<TreeNode*> s;
    TreeNode* cur=root;
    while(cur||!s.empty())
    {
        if(cur)//遍历左子树
        {
            cout<<cur->val<<endl;
            s.push(cur);
            cur=cur->left;
        }
        else
        {
            cur=s.top();s.pop();
            cur=cur->right;
        }
    }
}

//中序遍历
void mid(TreeNode* root)
{
    if(!root)
        return;

    mid(root->left);
    cout<<root->val<<endl;
    mid(root->right);
}

void mid2(TreeNode* root)
{
    if(!root)
        return;

    stack<TreeNode*> s;
    TreeNode* cur=root;
    while(cur||!s.empty())
    {
        if(cur)
        {
            s.push(cur);
            cur=cur->left;
        }
        else
        {
            cur=s.top();s.pop();
            cout<<cur->val<<endl;
            cur=cur->right;
        }
    }
}

//后序遍历
void post(TreeNode* root)
{
    if(!root)
        return;

    post(root->left);
    post(root->right);
    cout<<root->val<<endl;
}

//用两个堆栈实现后序遍历很简单
void post2(TreeNode* root)
{
    if(!root)
        return;

    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(root);

    while(!s1.empty())
    {
        TreeNode* cur=s1.top();s1.pop();
        s2.push(cur);
        if(cur->left)
            s1.push(cur->left);
        if(cur->right)
            s1.push(cur->right);
    }

    while(!s2.empty())
    {
        cout<<s2.top()->val<<endl;
        s2.pop();
    }
}

//广度遍历
void level(TreeNode* root)
{
    if(!root)
        return;
    
    queue<TreeNode*> q;
    q.push(root);

    int levels=0;
    while(!q.empty())
    {
        levels=q.size();
        for(int i=0;i<levels;i++)
        {
            TreeNode* cur=q.front();q.pop();
            cout<<cur->val<<endl;

            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }

    }
}

void createBT(TreeNode* root)
{
    cout<<"pre input BT"<<endl;
    char ch;
	cin >> ch;
	if ( ch == '#' )
		root = nullptr;
	else
	{
		root = new TreeNode(ch);
		createBT(root->left);
		createBT(root->right);
	}
}
*/

/************************************************* */
/*二叉树与递归 */
/************************************************* */

//树的子结构
//二叉树的镜像
//二叉搜索树的后序遍历序列
//平衡二叉树
//对称二叉树

#endif