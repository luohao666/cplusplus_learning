/*
 * @Author: luohao 
 * @Date: 2020-07-26 19:14:52 
 * @Last Modified by: luohao
 * @Last Modified time: 2020-07-26 19:57:38
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#include <sys/ioctl.h>
#include <sys/soundcard.h>

#include <fcntl.h>

#define BASE_VALUE 257
 
namespace AdjustVolume
{
    void usage(int argc,char* argv[],char* names[])
    {
        printf("usage: %s dev_no.[0..24] value[0..100]\n",argv[0]);
        printf("eg. %s 0 100\n",argv[0]);
        printf("will change the volume to MAX volume.\n");
        printf("the dev_no. are as below:\n");    
        for(int i=0;i<SOUND_MIXER_NRDEVICES;i++)
        {
            if(i%3==0)
            {
                printf("\n");
            }
            printf("%s:%d\t\t",names[i],i);
        }
        printf("\n");
    }

    int app(int argc,char* argv[])
    {
        int mixer_fd = 0;
        char* names[SOUND_MIXER_NRDEVICES]=SOUND_DEVICE_LABELS;
        int value;
        int i;

        usage(argc,argv,names);
        if(argc <3)
        {
            exit(-1);
        }

        if(mixer_fd = open("/dev/mixer",O_RDWR))
        {
            printf("Mixer opened successfully\n");
            value = BASE_VALUE*atoi(argv[2]);                        //string -> int
            
            if(ioctl(mixer_fd,MIXER_WRITE(atoi(argv[1])),&value)==0)       //hardware is sleep????????
            {
                printf("ioctl successfully\n");
            }
            else
            {
                printf("ioctl unsuccessfully\n");
            }
            
        }
        else
        {
            printf("Mixer opened unsuccessfully\n");
        }
        
        return 1;
    }
}