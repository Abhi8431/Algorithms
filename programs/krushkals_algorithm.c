#include <stdio.h>
int c[10][10],parents[10],i,j,k,count=0,cost=0,min,n,x,y,flag=0;

void find_min()
{
    min=999;
    for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
    {
        if(c[i][j]<min)
        {
            min=c[i][j];
            x=i;
            y=j;
        }
    }
    }
}

int check_cycle()
{
    if((parents[x] == parents[y])&&(parents[x]!=0))
        return 0;
    else if(parents[x]==0 && parents[y]==0)
        parents[x]=parents[y]=x;
    else if(parents[x]==0)
        parents[x]=parents[y];
    else if(parents[x]!=parents[y])
        parents[y]=parents[x];
    return 1;
}

int main()
{
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    printf("Enter 999 if no direct edges and self loops\n");
    for(i=1;i<=n;i++)
    {
        parents[i]=0;
        for(j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    }

    while(count!=n-1 && min!=999)
    {
       find_min();
       flag=check_cycle();
       if(flag==1)
       {
           printf("%d-->%d=%d\n",x,y,c[x][y]);
           count++;
           cost+=c[x][y];
       }
       c[x][y]=c[y][x]=999;
    }
    printf("The cost of minimum spanning tree is %d",cost);
    
    return 0;
}
