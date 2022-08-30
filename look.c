#include<stdio.h>
#include<stdlib.h>
//It is similar to the SCAN disk scheduling algorithm except for the difference that the disk arm in spite of going to the end of the disk goes only to the last request to be serviced in front of the head and then reverses its direction from there only. 
//Thus it prevents the extra delay which occurred due to unnecessary traversal to the end of the disk. 

//ADVANTAGES
/*
    1.If there are no requests left to be services the Head will not move to the end of the disk unlike SCAN algorithm.
    2.Low variance is provided in waiting time and response time
*/

//DISADVANTAGES
/*
    1.Overhead of finding the end requests is present.
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
        initial=track[i+1];
        printf("%d\t\t\t%d\n",initial,abs(track[i+1]-initial));
        
        for(i=pos;i<=trackn;i++)
        {
            printf("%d\t\t\t%d\n",track[i],abs(track[i]-initial));
            tothead+=abs(track[i]-initial);
            initial=track[i];
        }
    }
    else
    {
        for(i=pos;i<=trackn;i++)
        {
            printf("%d\t\t\t%d\n",track[i],abs(track[i]-track[i-1]));
            tothead+=abs(track[i]-track[i-1]);
        }
    
        limit=track[trackn];
        for(i=pos-2;i>=0;i--)
        {
            printf("%d\t\t\t%d\n",track[i],abs(track[i]-limit));
            tothead+=abs(track[i]-limit);
            limit=track[i];
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
