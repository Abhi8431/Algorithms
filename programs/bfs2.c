//bfs
#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
int a[10][10], c[10], count = 1, n, q[10], l=0, h=0;

void BFS(int v)
{
    c[0] = 1;
    printf("iteration %d\n",v);
    for(int i=0; i<n; i++)
    {
        if((a[v][i] == 1) && (c[i] == 0))
        {
            q[h] = i;
            h = h + 1;
            c[i] = ++count;
            printf("%d --> %d\n",i,count);
        }
    }
    if(l<=h)
    {
        BFS(q[l++]);
    }
}

int main()
{
    struct timeval tv1, tv2;
    struct rusage r;
    printf("Edges : "); 
     scanf("%d",&n);
    printf("Adjacency:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf(" %d",&a[i][j]);
    for(int i=0; i<n; i++)
    {
        c[i] = 0;
        q[0] = 0;
    }
    gettimeofday(&tv1, NULL);
    for(int i=0; i<n; i++)
        if(c[i] == 0)
            BFS(i);
    gettimeofday(&tv2, NULL);
    printf("\n");
    for(int i=0; i<n; i++)
        printf("%d ",c[i]);
    getrusage(RUSAGE_SELF, &r);
    printf("\nTime = %f microsec\n",(double)(tv2.tv_usec - tv1.tv_usec));
    printf("%ld KB",r.ru_maxrss);
    
}

