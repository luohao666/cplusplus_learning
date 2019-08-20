#ifndef __MYSTR_H__
#define __MYSTR_H_

#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

//strcpy
char* strcpy(char* dst,const char* src)
{
    assert(dst!=NULL&&src!=NULL);//值为0，打印出错信息
    
    if(dst!=NULL&&src!=NULL)
    {
        char* res=dst;
        while(*src!='\0')
            *dst++=*src++;
        *dst='\0';
        return res;
    }
    else
        return NULL;
}

//memcpy
void* memcpy(void* dst,const void* src,size_t s)
{
    const char* psrc=static_cast<const char*>(src);
    char* pdst=static_cast<char*>(dst);

    if(psrc==NULL||pdst==NULL)
        return NULL;
    
    if(pdst>psrc&&pdst<psrc+s)
    {
        for(size_t i=s-1;i!=-1;i--)
            pdst[i]=psrc[i];
    }
    else
    {
        for(size_t i=0;i!=s;i++)
            pdst[i]=psrc[i];
    }
    return dst;
}

//空格替换:向前计数,向后替换
//第一次只出现过一次的字符:map<char,int>
//左旋转字符串:XY=(X'Y')'
//翻转单词序列:空格切割字符串的方法(前后指针)
//字符串换成整数:"123"-->res=res*10+a[i]
//数组排成的最小数:自定义cmp,to_string

#endif