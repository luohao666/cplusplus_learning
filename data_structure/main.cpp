#include <iostream>
#include "mysort.h"
#include "myBT.h"
#include "myList.h"
#include "mySearch.h"
#include "mystr.h"
#include "my.h"

using namespace std;

int main(int argc,char* argv[])
{
/* 
    cout<<"mysort"<<endl;
    mysort mysort;
    int a[] ={5,4,6,3,2};
    vector<int> data(a,a+5);

//   mysort.normalSort(data);
//    mysort.print(data);

//    quickSort(data,0,4);
    quickSort2(data,0,4);
    mysort.print(data);

//    vector<int> copy(a,a+5);
//    mergeSort(data,0,4,copy);
//    mysort.print(data);
*/

/* 
    cout<<"myBT"<<endl;
    TreeNode<int>* root=new TreeNode<int>(1);
    root->left=new TreeNode<int>(2);
    root->right=new TreeNode<int>(3);
    root->left->left=new TreeNode<int>(4);

    cout<<"pre"<<endl;pre(root);
    cout<<"pre2"<<endl;pre2(root);
    cout<<"mid"<<endl;mid(root);
    cout<<"mid2"<<endl;mid2(root);
    cout<<"post"<<endl;post(root);
    cout<<"post2"<<endl;post2(root);
*/

//    cout<<"level"<<endl;level(root);
//    cout<<"deep"<<endl;deep(root);

//    float sum=3*80+2*93+90*1+80*3+88*1+80*4+89*4+87*3+80*3+92*1;
//    float weight=3+2+1+3+1+4+4+3+3+1;
//    cout<<sum<<endl;
//    cout<<weight<<endl;
//    cout<<sum/weight<<endl;

 /* 
    cout<<"myList"<<endl;
    ListNode<int>* root= new ListNode<int>(7);
    root->next=new ListNode<int>(4);
    root->next->next=new ListNode<int>(1);
    cout<<"list:"<<endl;
    print(root);

    selectSort(root);
//    ListNode<int>* end=NULL;
//    quickSortLinkList(root,end);
    print(root);

*/


    /* 
    ListNode<int>* inv= NULL;
    inv=inverse(root);
    cout<<"invlist:"<<endl;
    print(inv);
    */

/* 
    ListNode<int>* root2= new ListNode<int>(2);
    root2->next=new ListNode<int>(5);
    root2->next->next=new ListNode<int>(6);
    cout<<"list2:"<<endl;    
    print(root2);
    ListNode<int>* mer= NULL;
    mer=merge2(root,root2);
    //mer=merge2(root,root2);
    cout<<"merge:"<<endl;
    print(mer);

    ListNode<int>* find= NULL;
    find=FindKthToTail(mer,3);
    cout<<"find:"<<endl;
    print(find);
*/

/* 
    int aa[5]={1,2,3,4,5};
    vector<int> data(aa,aa+5);
    cout<<binarySearch(data,0)<<endl;
*/

/* 
    char* src="hello";
    char dst[6];
    char* res;
    res=strcpy(dst,src);
    cout<<strlen(res)<<endl;
    for(int i=0;i<strlen(res);i++)
        cout<<res[i];
    cout<<endl;
*/

/* 
    //int aa[5]={5,1,2,3,4};
    int aa[5]={1,0,1,1,1};
    vector<int> data(aa,aa+5);
    cout<< minv_rotate_array(data) <<endl;
*/

    int aa[5]={1,2,3,4,5};
    vector<int> data(aa,aa+5);
    reOrderArray(data);
    for(int i=0;i<data.size();i++)
        cout<<data[i];
    cout<<endl;

    return 0;
}