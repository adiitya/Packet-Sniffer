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
/*
HOW IT WORKS:
1. After connecting to the device it continuously hops between different channels.
   It randomly chooses another channel till that channel has spent 1 minute time in total.
   After a channel has complete result it prints it till result is done for each channel
   and Finally result is obtained.
   Rest the code is commented for better understanding.
*/

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

/*
    This function captures any packet coming in the current channel
    and analyses it and feeds it in our data set.
*/
void capture_and_analyse(const u_char* packet, int len) {


    temp1 = new char[100];
    temp2 = "";
    int start;

    bool toDS = packet[19] & (1 << 8);
    bool fromDS = packet[19] & (1 << 7);

    if( fromDS==0)
        start = 28;
    else if(toDS==1 && fromDS==1)
        start = 42;
    else
        start = 34;
    //Finds from
    //Gets the part having mac_id
    for(int k=start; k <= start+5; k++){
       sprintf(temp1,"%02X", packet[k]);
       temp2 += temp1[0];
       temp2 += temp1[1];
       if(k!=start+5)
          temp2 += ":";
    }
    time_t curr = time(NULL);
    cout << "Mac_id " << temp2 << " received at " << asctime(localtime(&curr)) ;

}

//Prints the global result
void print_observation()
{
    cout<< "Output in terms of number of packets captured : "<<endl;
    for(int i=0;i<13;i++)
        printf("Channel %d received total %d packets\n",i+1,packets[i]);
    cout << endl;
    cout << "Across all channels : ";
    cout << endl;
    for(map<string,int>::iterator itr = global_mac.begin(); itr != global_mac.end(); itr++){
       cout<<"Mac_id " << (*itr).first << " has appeared " << (double)((*itr).second)/13.0 << " times per minute" << endl;
    }
    cout << endl;
    exit(0);
}

//Calls the packet capturer for each channel
void handle_capture(const struct pcap_pkthdr* pkthdr,const u_char*
        packet)
{
    capture_and_analyse(packet, pkthdr->len);
}

//Prints the output collected per channel
void printChannel(int channel)
{
    printed[channel]=true;
    cout<<"Number of packets received in channel "<< channel+1 <<" : "<<packets[channel]<<endl;
    cout << endl;
    for(map<string,int>::iterator itr = mac_count[channel].begin();itr!=mac_count[channel].end();itr++)
    {
        cout<<"Mac_id " << (*itr).first << " " << " has been received " << (*itr).second << " time(s) in channel " << channel+1 << endl;
    }
    cout << endl;
    int counter = 0;
    for(int i=0;i<13;i++){
        if(!printed[i])
            counter++;
        if(counter==1)
            print_observation();
    }

}

//Gives a channel for which complete 1 min is not spent and if so it prints result for it.
int getChannel()
{
    int c1 = rand()%13;
    if(time_spent[c1] < 6)
    {
        return c1;
    }
    else
    {
        if(!printed[c1])
            printChannel(c1);
        printed[c1] = true;
        return -1;
    }
}

//Changes channel and listens there for MAX_TIME
void core_channel(int cid){
    //change to channel
    string channel_str = "iw dev wlan2 set channel ";
    char* tem = new char[2];
    sprintf(tem, "%d", cid+1);
    channel_str += tem;
    cout<<"Scanning channel "<< cid + 1 << "..." << endl;
    cout << endl;
    system(channel_str.c_str());
    time_t end = time(NULL) + MAX_TIME;
    while(time(NULL) <= end){
        //pcap_loop(descr,handle_capture,NULL);
        struct pcap_pkthdr hdr;
        u_char* packet = (u_char*)pcap_next(descr,&hdr);
        if(packet==NULL)
            continue;
        handle_capture(&hdr,packet);
        packets[cid]++;

        mac_count[cid][temp2]++;
        global_mac[temp2]++;
    }
    cout << endl;
    time_spent[cid] += MAX_TIME;
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



