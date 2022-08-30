#include<stdio.h>
#include<stdlib.h>

// LEAST RECENTLY USED
//Least Recently Used (LRU) page replacement algorithm works on the concept that the pages that are heavily used in previous instructions are likely to be used heavily in next instructions. 
//And the page that are used very less are likely to be used less in future. 
//Whenever a page fault occurs, the page that is least recently used is removed from the memory frames. 
//Page fault occurs when a referenced page in not found in the memory frames.
int main()
{
    int page[100],frame[10],pagefault=0,i,j,k,fcount,pcount,flag=0,q=0,p,f,far=99,qt;
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
    while(q<pcount)
    {
        printf("%d\t\t\t\t\t\t",page[q]);
        for(i=0;i<fcount;i++)
        {
            if(frame[i]==page[q])
            {
                flag=1;
            }
        }
        if(flag==0&&q<=fcount)
        {
            printf("q=%d",q);
            if(q==fcount)
            {
                qt=q-1;
                frame[qt]=page[q];
            }
            else{
                frame[q]=page[q];
            }
            frame[q]=page[q];
            q++;
            pagefault++;
            for(j=0;j<fcount;j++)
            {
                printf("%d\t\t\t",frame[j]);
            }
            printf("\n");
        }
        else if(flag==0)
        {
            pagefault++;
            for(i=0;i<fcount;i++)
            {
                for(j=0;j<q;j++)
                {
                    if(frame[i]==page[j])
                    {
                        f=j;
                    }
                }
                if(far>f)
                {
                    far=f;
                    p=i;
                }
            }
            frame[p]=page[q];
            q++;
            far=99;
            for(j=0;j<fcount;j++)
            {
                printf("%d\t\t\t",frame[j]);
            }
            printf("\n");
        }
        else
        {
            ++q;
            printf("<<HIT>>\n");
        }
        flag=0;
        printf("\n");
    }
    printf("The page fault is => %d\n",pagefault);
}
