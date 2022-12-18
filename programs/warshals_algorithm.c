//warshall
#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
int a[10][10], n;

void warshall()
{
    for(int k = 0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
}

void main()
{
    struct timeval tv1, tv2;
    struct rusage r;
    printf("size : "); scanf("%d",&n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    gettimeofday(&tv1, NULL);
    warshall();
    gettimeofday(&tv2, NULL);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("t-->%f microseconds\n",(double)(tv2.tv_usec-tv1.tv_usec));
    getrusage(RUSAGE_SELF, &r);
    printf("%ld KB\n",r.ru_maxrss);

 
}



