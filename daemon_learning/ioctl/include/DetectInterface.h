/*
 * @Author: luohao 
 * @Date: 2020-07-26 19:14:47 
 * @Last Modified by:   luohao 
 * @Last Modified time: 2020-07-26 19:14:47 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace DetectInterface
{
    void usage()
    {
        printf("usage: ifconfig interface\n");
        exit(0);
    }

    int app(int argc, char* argv[])
    {
        struct sockaddr_in *addr;                        //socket               
        struct ifreq ifr;                                //ifreq
        char *name;
        char *address;
        int sockfd;

        if(argc!=2)
        {
            usage();
        }
        else
        {
            name = argv[1];
        }
        
        sockfd = socket(AF_INET,SOCK_DGRAM,0);
        strncpy(ifr.ifr_ifrn.ifrn_name,name,IF_NAMESIZE-1);

        if(ioctl(sockfd,SIOCGIFADDR,&ifr) == -1)
        {
            perror("ioctl error"),exit(1);
        }
        addr = (struct sockaddr_in*) &(ifr.ifr_ifru.ifru_addr);
        address = inet_ntoa(addr->sin_addr);
        printf("inet addr:%s\n",address);

        if(ioctl(sockfd,SIOCGIFBRDADDR,&ifr) == -1)
        {
            perror("ioctl error"),exit(1);
        }
        addr = (struct sockaddr_in*) &(ifr.ifr_ifru.ifru_broadaddr);
        address = inet_ntoa(addr->sin_addr);
        printf("board addr:%s\n",address);

        if(ioctl(sockfd,SIOCGIFNETMASK,&ifr) == -1)
        {
            perror("ioctl error"),exit(1);
        }
        addr = (struct sockaddr_in*) &(ifr.ifr_ifru.ifru_addr);
        address = inet_ntoa(addr->sin_addr);
        printf("inet mask:%s\n",address);
        return -1;
    }
}
