#include <stdio.h>


//set up packet structures

extern struct rtpkt {
    int sourceid;
    int destid;
    int mincost[4];
};

extern int TRACE;
extern int YES;
extern int NO;

struct distance_table
{
    int costs[4][4];
} dt0;


struct rtpkt packet;
/* students to write the following two routines, and maybe some others */

void rtinit0()
{
    
    //sets minimum cost higher than default distance weights
	packet.mincost[0] = 999;
	packet.mincost[1] = 999;
	packet.mincost[2] = 999;
	packet.mincost[3] = 999;
    
	
    printf("rinit0 function");
	
	int i;
	int j;
    
	//sets standard distance at high weight
	for(i=0;i<4;i++)
	{
		for(j=0; j<4; j++)
		{
			dt0.costs[i][j]= 999;
		}
	}
    
    //sets the direct distances/weight for nodes
	dt0.costs[1][1]=1;
	dt0.costs[2][2]=3;
	dt0.costs[3][3]=7;
    
	//check weighted path cost
	for(i=0;i<4;i++)
	{
		for(j=0; j<4; j++)
		{
			if(packet.mincost[i] > dt0.costs[i][j])
				packet.mincost[i] = dt0.costs[i][j];
		}
	}
    
    //set packet's sourceid to 0, since this code is for node 0
	packet.sourceid = 0;
	packet.destid = 1;
	tolayer2(packet);
	packet.sourceid = 0;
	packet.destid = 2;
	tolayer2(packet);
	packet.sourceid = 0;
	packet.destid = 3;
	tolayer2(packet);
	printdt0(&dt0);
	printf("done with rtinit0\n");
}

/*updates the distance vector table in case of changes*/
void rtupdate0(rcvdpkt)
struct rtpkt *rcvdpkt;
{
	//setting all minimum weights high
    packet.mincost[0] = 999;
	packet.mincost[1] = 999;
	packet.mincost[2] = 999;
	packet.mincost[3] = 999;
    
	//prints out updates of packets sent to sourceid = node 0
	extern float clocktime;
	printf("rtupdate0: %f\n node: %d\n", clocktime, rcvdpkt->sourceid);
	printdt0(&dt0);
    
	
	int change = 0;
	int i;
	int j;
	for(i = 0; i < 4; ++i)
	{
		//checks for packet updates to table
		if(dt0.costs[i][rcvdpkt->sourceid] > dt0.costs[rcvdpkt->sourceid][rcvdpkt->sourceid] + rcvdpkt->mincost[i])
		{
			dt0.costs[i][rcvdpkt->sourceid] = dt0.costs[rcvdpkt->sourceid][rcvdpkt->sourceid] + rcvdpkt->mincost[i];
			change = 1;
		}
	}
	//if the change has actually happened, update table, overwrite high distance set at 999
	if(change)
	{
		for(i=0;i<4;i++)
		{
			for(j=0; j<4; j++)
			{
				if(packet.mincost[i]  > dt0.costs[i][j])
					packet.mincost[i] = dt0.costs[i][j];
			}
		}
        
		printf("updated distance\n");
		
		//calls packet from tolayer2
		packet.sourceid = 0;
		packet.destid = 1;
		tolayer2(packet);
		packet.sourceid = 0;
		packet.destid = 2;
		tolayer2(packet);
		packet.sourceid = 0;
		packet.destid = 3;
		tolayer2(packet);
	}
	//pretty prints data
	printdt0(&dt0);
}


printdt0(dtptr)
struct distance_table *dtptr;
{
    printf("                via     \n");
    printf("   D0 |    1     2    3 \n");
    printf("  ----|-----------------\n");
    printf("     1|  %3d   %3d   %3d\n",dtptr->costs[1][1],
           dtptr->costs[1][2],dtptr->costs[1][3]);
    printf("dest 2|  %3d   %3d   %3d\n",dtptr->costs[2][1],
           dtptr->costs[2][2],dtptr->costs[2][3]);
    printf("     3|  %3d   %3d   %3d\n",dtptr->costs[3][1],
           dtptr->costs[3][2],dtptr->costs[3][3]);
    return 0;
}

linkhandler0(linkid, newcost)
int linkid, newcost;
{
    return 0;
}
