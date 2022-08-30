#include<stdio.h>
#include<stdlib.h>

//As LOOK is similar to SCAN algorithm, in similar way, CLOOK is similar to CSCAN disk scheduling algorithm. 
//In CLOOK, the disk arm in spite of going to the end goes only to the last request to be serviced in front of the head and then from there goes to the other end’s last request. 
//Thus, it also prevents the extra delay which occurred due to unnecessary traversal to the end of the disk. 

//Advantages
/*
    1.Starvation is avoided in C-LOOK.
    2.Low variance is provided in waiting time and response time.
*/

//Disadvantages
/*
    1.An overhead to find the end request.
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
        
        for(i=trackn;i<=pos;i++)
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
        for(i=0;i<pos-1;i++)
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
