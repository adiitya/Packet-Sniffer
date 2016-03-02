#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include<iostream>
#include <string.h>
#include<cstring>
#include<map>
#include<ctime>
#include<cmath>
#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;

int time_spent[13];//Defines how much time has been spent on a channel
bool printed[13];//Is a channel result printed or not.
int packets[13];//packet count for each channel


void start(){

}

//Initialise global variables.
void init()
{
    for(int i=0;i<13;i++)
        printed[i] = false;
}
int main(int argc, char** argv)
{

    dev = argv[1];

    //CHECKS IF
    if(dev == NULL)
    { printf("NO DEVICE %s\n",errbuf); exit(1); }
    /* open device for reading */

    descr = pcap_open_live(dev,BUFSIZ,1,-1,errbuf);
    if(!descr){
        cout<<endl<<"No devide found..Please connect device."<<endl;
        exit(0);
        }
    init();
    start();
    return 0;
}


