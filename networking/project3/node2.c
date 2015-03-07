#include <stdio.h>


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
} dt2;


struct rtpkt packet;
/* students to write the following two routines, and maybe some others */

void rtinit2()
{
	packet.mincost[0] = 999;
	packet.mincost[1] = 999;
	packet.mincost[2] = 999;
	packet.mincost[3] = 999;
    
	extern float clocktime;
    
	printf("rtinit2\n");
	printf("rtinit2: %f\n", clocktime);
	int i;
	int j;
    
	for(i=0;i<4;i++)
	{
		for(j=0; j<4; j++)
		{
			dt2.costs[i][j]= 999;
            
		}
	}
    
    dt2.costs[0][0]=3;
	dt2.costs[1][1]=1;
	dt2.costs[2][2]=999;
	dt2.costs[3][3]=2;
    
	for(i=0;i<4;i++)
	{
		for(j=0; j<4; j++)
		{
			if(packet.mincost[i] > dt2.costs[i][j])
				packet.mincost[i] = dt2.costs[i][j];
		}
	}
    
	packet.sourceid = 2;
	packet.destid = 0;
	tolayer2(packet);
	packet.sourceid = 2;
	packet.destid = 1;
	tolayer2(packet);
	packet.sourceid = 2;
	packet.destid = 3;
	tolayer2(packet);
    
	printdt2(&dt2);
	printf("done with rtinit2\n");
}

/*updates data in distance table in case of changes*/
void rtupdate2(rcvdpkt)
struct rtpkt *rcvdpkt;
{
    
	packet.mincost[0] = 999;
	packet.mincost[1] = 999;
	packet.mincost[2] = 999;
	packet.mincost[3] = 999;
    
	extern float clocktime;
	printf("rtupdate2: %f\n node: %d\n", clocktime, rcvdpkt->sourceid);
	printdt2(&dt2);
    
	int change = 0;
	int i;
	int j;
	for(i = 0; i < 4; ++i)
	{
		if(dt2.costs[i][rcvdpkt->sourceid] > dt2.costs[rcvdpkt->sourceid][rcvdpkt->sourceid] + rcvdpkt->mincost[i])
		{
			dt2.costs[i][rcvdpkt->sourceid] = dt2.costs[rcvdpkt->sourceid][rcvdpkt->sourceid] + rcvdpkt->mincost[i];
			change = 1;
		}
	}
	if(change)
	{
		for(i=0;i<4;i++)
		{
			for(j=0; j<4; j++)
			{
				if(packet.mincost[i] > dt2.costs[i][j])
					packet.mincost[i] = dt2.costs[i][j];
			}
		}
        
		printf("updated distance\n");
        
		packet.sourceid = 2;
		packet.destid = 0;
		tolayer2(packet);
		packet.sourceid = 2;
		packet.destid = 1;
		tolayer2(packet);
		packet.sourceid = 2;
		packet.destid = 3;
		tolayer2(packet);
	}
	printdt2(&dt2);
}


printdt2(dtptr)
struct distance_table *dtptr;

{
    printf("                via     \n");
    printf("   D2 |    0     1    3 \n");
    printf("  ----|-----------------\n");
    printf("     0|  %3d   %3d   %3d\n",dtptr->costs[0][0],
           dtptr->costs[0][1],dtptr->costs[0][3]);
    printf("dest 1|  %3d   %3d   %3d\n",dtptr->costs[1][0],
           dtptr->costs[1][1],dtptr->costs[1][3]);
    printf("     3|  %3d   %3d   %3d\n",dtptr->costs[3][0],
           dtptr->costs[3][1],dtptr->costs[3][3]);
    return 0;
}

