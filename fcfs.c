#include<stdio.h>
#include<stdlib.h>


// FCFS Disk Scheduling is the simplest of all the Disk Scheduling Algorithms. 
//In FCFS, the requests are addressed in the order they arrive in the disk queue.
//Advantages
/*
    1.easy to understand and implement
    2. No starvation occur
    */
//Disadvantages
/*
    1.Throughput is not very efficient
    2.Waiting and response time is more
*/
int main()
{
    int tothead=0,track[100],trackn,head,i,j,k;
    double avg;
    // Information from the user
    printf("Enter the Head\n");
    scanf("%d",&head);
    track[0]=head;
    printf("Enter the number of tracks:\n");
    scanf("%d",&trackn);
    printf("Enter the track sequence:\n");
    // 0th position to head
    for(i=1;i<=trackn;i++)
    {
        scanf("%d",&track[i]);
    }
    // start from prev-current
    printf("Track sequence\t|| Head Movement\n");
    for(i=1;i<=trackn;i++)
    {
        tothead+=abs(track[i-1]-track[i]);
        printf("%d\t\t%d\n",track[i],abs(track[i-1]-track[i]));
    }
    avg=tothead/(double)trackn;
    printf("Total Head movement = %d\n",tothead);
    printf("Average Head movement = %f\n",avg);

    return 0;
}
