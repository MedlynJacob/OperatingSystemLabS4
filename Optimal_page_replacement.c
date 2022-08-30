#include<stdio.h>
#include<stdlib.h>

//Optimal page replacement algorithm says that if page fault occurs then that page should be removed that will not be used for maximum time in future.
//It is also known as clairvoyant replacement algorithm or Bélády’s optimal page replacement policy.
int main()
{
    int page[100],frame[10],pagefault=0,i,j,k,fcount,pcount,flag1=0,flag2=0,flag3=0,q=0,p,f,far=99,temp[10];
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
        printf("%d\t\t\t\t\t\t",page[i]);
        flag1=flag2=0;
        for(j=0;j<fcount;j++)
        {
            if(frame[j]==page[i])
            {
                flag1=flag2=1;
                printf("<<HIT>>");
                break;
            }
        }
        if(flag1==0)
        {
            for(j=0;j<fcount;j++)
            {
                if(frame[j]==-1)
                {
                    pagefault++;
                    frame[j]=page[i];
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2==0)
        {
            flag3=0;
            for(j=0;j<fcount;j++)
            {
                temp[j]=-1;
                for(k=i+1;k<pcount;++k)
                {
                    if(frame[j]==page[k])
                    {
                        temp[j]=k;
                        break;
                    }
                }
            }
            for(j=0;j<fcount;j++)
            {
                if(temp[j]==-1)
                {
                    q=j;
                    flag3=1;
                    break;
                }
            }
            if(flag3==0)
            {
                far=temp[0];
                q=0;
                for(j=1;j<fcount;++j)
                {
                    if(temp[j]>far)
                    {
                        far=temp[j];
                        q=j;
                    }
                }
            }
            frame[q]=page[i];
            pagefault++;
        }
        for(j=0;j<fcount;j++)
        {
            printf("%d\t\t",frame[j]);
        }
        printf("\n");
    }
    printf("The page fault is => %d\n",pagefault);
}
