#include<stdio.h>
#include<stdlib.h>
//The banker’s algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation for predetermined maximum possible amounts of all resources, 
//then makes an “s-state” check to test for possible activities, before deciding whether allocation should be allowed to continue.
// MAX, ALLOCATION, NEED=MAX-ALLOCATION, AVAILABLE,DISPLAY SAFE SEQUENCE AND CORRESPONDING AVAILABLE RESOURCES
int main()
{
    int n,m,i,j,k,alloc[10][10],max[10][10],need[10][10],avail[10],f[10],w=0,seq[10],flag;
    printf("ENTER THE NUMBER OF PROCESS\n");
    scanf("%d",&n);
    printf("ENTER THE NUMBER OF RESOURCES\n");
    scanf("%d",&m);
    printf("Enter the No. of Allocation of each resource to each process\n");
    for(i=0;i<n;i++)
    {
        printf("For P%d\n",i);
        for(j=0;j<m;j++)
        {
            printf("R%d\n",j);
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the Maximum no. of each resource to each process\n");
    for(i=0;i<n;i++)
    {
        printf("For P%d\n",i);
        for(j=0;j<m;j++)
        {
            printf("R%d\n",j);
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the available resouces\n");
    for(i=0;i<m;i++)
    {
        printf("for R%d",i);
        scanf("%d",&avail[i]);
    }

    printf("Allocation MATRIX:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t\t",i);
        for(j=0;j<m;j++)
        {
            printf("R%d \t\t %d",j,alloc[i][j]);
        }
        printf("\n");
    }
    printf("MAX MATRIX:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t\t",i);
        for(j=0;j<m;j++)
        {
            printf("R%d \t\t %d",j,max[i][j]);
        }
        printf("\n");
    }

    printf("NEED MATRIX:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t\t",i);
        for(j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
            printf("R%d \t\t %d",j,need[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<n;i++)
    {
        f[i]=0;
    }
    flag=0;
    for(int y=0;y<n;y++)
    {
        for(i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>avail[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    seq[w++]=i;
                    printf("\nNew available matrix after execution of P%d\n",i);
                    for(k=0;k<m;k++)
                    {
                        avail[k]+=alloc[i][k]; 
                        printf("%d\t\t",avail[k]);
                        f[i]=1;
                    }
                }

            }
        }
    }
    flag=1;
    for(i=0;i<n;i++)
    {
        if(f[i]==0)
        {
            flag=0;
            printf("NOT SAFE\n");
            break;
        }
    }
    if(flag==1)
    {
        printf("Safe sequence is:\n");
        for(i=0;i<n-1;i++)
        {
            printf("P%d => ",seq[i]);
        }
        printf("P%d\n",seq[n-1]);
    }
    return 0;
}
