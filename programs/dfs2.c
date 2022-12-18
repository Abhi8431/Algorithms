//dfs
#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
int a[20][20], c[20],n, count = 1;

void dfs(int v)
{
    int i;
    c[v] = count++;
    for(int i=0; i<n; i++)
    {
        if((a[v][i]==1)&&(c[i]==0))
            dfs(i);
    }
}

int main()
{
    int n;
    struct timeval tv1, tv2;
    struct rusage r;
    printf("edges: "); 
    scanf("%d",&n);
    printf("Adjacency:\n");
    for(int i=0; i<n; i++)
    {
        c[i] = 0;
        for(int j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    }
    gettimeofday(&tv1, NULL);
    for(int i=0; i<n; i++)
        dfs(i);
    gettimeofday(&tv2, NULL);
    for(int i=0; i<n; i++)
        printf(" %d ", c[i]);
    printf("\n %f sec", (double)(tv2.tv_usec-tv1.tv_usec));
    getrusage(RUSAGE_SELF, &r);
    printf("\n%ld kb ", r.ru_maxrss);
}

