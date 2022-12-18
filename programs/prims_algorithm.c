#include <stdio.h>
#include<time.h>
#include<sys/time.h>
#include<sys/resource.h>
int c[10][10],i,j,k,count,min,n,visited[10],a,b,cost=0;

void prims()
{
    visited[1]=1;
    min=999;
    while(count<n-1)
    {
        min=999;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
            {
                if(visited[i] && !visited[j] && min>c[i][j])
                {
                    min=c[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        printf("%d-->%d=%d\n",a,b,c[a][b]);
        cost+=c[a][b];
        count++;
        visited[b]=1;
    }
    printf("The minimum spanning cost is %d\n",cost);
}
int main()
{   struct timeval tv1, tv2;
    struct rusage r;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    printf("Enter 999 if no edges between vertices:\n");
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        for(j=1;j<=n;j++)
        scanf("%d",&c[i][j]);
    }
    gettimeofday(&tv1, NULL);
    prims();
    gettimeofday(&tv2, NULL);
    printf("\nt-->%f microseconds\n",(double)(tv2.tv_usec-tv1.tv_usec));
    getrusage(RUSAGE_SELF, &r);
     printf("%ld KB\n",r.ru_maxrss);
    return 0;
}
