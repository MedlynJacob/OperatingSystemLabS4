#include<stdio.h>
#include<stdlib.h>
// In SCAN algorithm, the disk arm again scans the path that has been scanned, after reversing its direction. 
//So, it may be possible that too many requests are waiting at the other end or there may be zero or few requests pending at the scanned area. 
//These situations are avoided in CSAN algorithm in which the disk arm instead of reversing its direction goes to the other end of the disk and starts servicing the requests from there. 
//So, the disk arm moves in a circular fashion and this algorithm is also similar to SCAN algorithm and hence it is known as C-SCAN (Circular SCAN). 

//ADVANTAGES
/*
    1.Uniform waiting time
    2.Better response time
*/
//DISADVANTAGES
/*
    1.In C-SCAN even if there are no requests left to be serviced the Head will still travel to the end of the disk unlike SCAN algorithm.
*/

int* sorting(int arr[],int n);
int fhpos(int head,int arr[],int in,int n);
int main()
{
    int tothead=0,track[100],trackn,head,i,j,k,prev_h,limit,move,pos,initial;
    double avg;
    int *sort;
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
    printf("Enter the previous head value:\n");
    scanf("%d",&prev_h);
    if(prev_h>head)
    {
        move=0;
    }
    else
    {
        move=1;
    }
    printf("Enter the last limit:\n");
    scanf("%d",&limit);
    sort=sorting(track,trackn);
    pos=fhpos(head,track,0,trackn);

    printf("Sequence\t|| HeadMovement\n");
    if(move==0)
    {
        for(i=pos-2;i>=0;i--)
        {
            printf("%d\t\t\t%d\n",track[i],abs(track[i]-track[i-1]));
            tothead+=abs(track[i]-track[i-1]);
        }
        initial=0;
        tothead+=abs(track[i+1]-0);
        printf("%d\t\t\t%d\n",initial,abs(track[i+1]-initial));
        tothead+=abs(limit-0);
        printf("%d\t\t\t%d\n",limit,abs(limit-0));
        
        for(i=trackn;i>pos-1;i--)
        {
            printf("%d\t\t\t%d\n",track[i],abs(track[i]-limit));
            tothead+=abs(track[i]-initial);
            limit=track[i];
        }
    }
    else
    {
        for(i=pos;i<=trackn;i++)
        {
            printf("%d\t\t\t%d\n",track[i],abs(track[i]-track[i-1]));
            tothead+=abs(track[i]-track[i-1]);
        }
    
        tothead+=abs(limit-track[i-1]);
        printf("%d\t\t\t%d\n",limit,abs(track[i-1]-limit));
        initial=0;
        tothead+=abs(limit-initial);
        printf("%d\t\t\t%d\n",initial,abs(limit-initial));
        for(i=0;i<pos-1;i++)
        {
            printf("%d\t\t\t%d\n",track[i],abs(track[i]-initial));
            tothead+=abs(track[i]-initial);
            initial=track[i];
        }
    }
    avg=tothead/(double)trackn;
    printf("Total Head movement = %d\n",tothead);
    printf("Average Head movement = %f\n",avg);
    return 0;
}

int* sorting(int arr[],int n)
{
    int temp,i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return arr;
}
int fhpos(int head,int arr[],int in,int n)
{
    int mid=(in+n)/2;
    if(arr[mid]==head)
    {
        return mid;
    }
    else if (arr[mid]>head)
    {
        return(head,arr,in,mid-1);
    }
    else
    {
        return(head,arr,mid+1,n);
    }
}
