/*
 * @Author: luohao 
 * @Date: 2020-07-26 10:38:44 
 * @Last Modified by: luohao
 * @Last Modified time: 2020-07-26 19:41:09
 */
#include <iostream>
#include <DetectInterface.h>
#include <AdjustVolume.h>

using namespace std;

int main(int argc,char* argv[])
{    
    cout << "demo" << endl;
    //DetectInterface::app(argc,argv);
    AdjustVolume::app(argc,argv);

    return -1;
}