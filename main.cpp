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

#define MAX_TIME 2
using namespace std;


int time_spent[13];//Defines how much time has been spent on a channel
bool printed[13];//Is a channel result printed or not.
int packets[13];//packet count for each channel

map<string,int> mac_count[13];//count for each mac_address per channel
map<string,int> global_mac;//mac_ids gloabal for all channels

int i;
char *dev;
char errbuf[PCAP_ERRBUF_SIZE];
pcap_t* descr;
const u_char *packet;
struct pcap_pkthdr hdr;     /* pcap.h */
struct ether_header *eptr;  /* net/ethernet.h */

char* temp1;
string temp2;

//Prints the global result
void print_observation() {

}

//Calls the packet capturer for each channel
void handle_capture(const struct pcap_pkthdr* pkthdr,const u_char*
        packet)
{

}

//Prints the output collected per channel
void printChannel(int channel) {

}

//Gives a channel for which complete 1 min is not spent and if so it prints result for it.
int getChannel()
{

}

//Changes channel and listens there for MAX_TIME
void core_channel(int cid) {

}

//Starts the working of program
void start()
{
    //change to sudo.
    //change to monitor mode
    while((printed[0] && printed[1] && printed[2] && printed[3] && printed[4] && printed[5] && printed[6] && printed[7] && printed[8] && printed[9] && printed[10] && printed[11] && printed[12]) == false)
    {
        int cid = -1;
        while(cid==-1){
        cid = getChannel();
        }
        core_channel(cid);
        if(printed[0] && printed[1] && printed[2] && printed[3] && printed[4] && printed[5] && printed[6] && printed[7] && printed[8] && printed[9] && printed[10] && printed[11] && printed[12]){
            cout<<"hua be"<<endl;break;
        }
    }
    print_observation();
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


