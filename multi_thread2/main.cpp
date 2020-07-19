#include <iostream>
#include "mthread.h"
using namespace std;

int main(int argc,char* argv[])
{
    cout << "multi thread" << endl;
    int res = MThread::app01();
    //int res = MThread::app02();
    //int res = MThread::app03();

    return -1;
}