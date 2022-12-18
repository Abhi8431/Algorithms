#include<stdio.h>
#include<time.h>
#include<sys/time>
#include<stdlib.h>

int min(int a,int b){
 return(a<b)?a:b;
}

void floyd(int a[][20],int n)
{
 int k,i,j;
 for (i=0;i<n;i++){
     for(j=0;j<n;j++){
        for(k=0;k<n;K++){
         a[j][k] = min(a[j][k],a[j][i]+a[i][k]);
          }
       }
   }       
}

 void main()
{
 int n,a[20][20],i,j;
    struct timeval tv1, tv2;
    printf("enter the number of nodes in the graph : "); 
    scanf("%d",&n);
    printf("enter weights matrix for the graph:");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&a[i][j]);
            }
       }
    gettimeofday(&tv1, NULL);
    floyd(a,n);
    gettimeofday(&tv2, NULL);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d/t ",a[i][j]);
        printf("\n");
    }
    printf("t-->%f microseconds\n",(double)(tv2.tv_usec-tv1.tv_usec));
}

