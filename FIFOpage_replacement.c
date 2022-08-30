#include<stdio.h>
#include<stdlib.h>

//Page Replacement - FIFO
//This is the simplest page replacement algorithm. 
//In this algorithm, the operating system keeps track of all pages in the memory in a queue, the oldest page is in the front of the queue. 
//When a page needs to be replaced page in the front of the queue is selected for removal. 

int main()
{
    int page[100],frame[10],pagefault=0,i,j,k,fcount,pcount,flag,q=0;
    printf("Enter the number of pages\n");
    scanf("%d",&pcount);
    printf("Enter the number of frames\n");
    scanf("%d",&fcount);
    printf("Enter the reference string\n");
    for(i=0;i<pcount;i++)
    {
        scanf("%d",&page[i]);
    }
    for(i=0;i<fcount;i++)
    {
        frame[i]=-1;
    }
    printf("REFERENCE SEQUENCE\t||\t\tframes\n");
    for(i=0;i<pcount;i++)
    {
        flag=0;
        printf("%d\t\t\t\t  ",page[i]);
        for(j=0;j<fcount;j++)
        {
            if(frame[j]==page[i])
            {
                flag=1;
                printf("<<HIT>>");
                break;
            }
        }
        if(flag==0)
        {
            frame[q]=page[i];
            pagefault++;
            q=(q+1)%fcount;
            for(k=0;k<fcount;k++)
            {
                printf("%d\t\t\t",frame[k]);
            }
        }
        printf("\n");
    }
    printf("The page fault is => %d\n",pagefault);
}
