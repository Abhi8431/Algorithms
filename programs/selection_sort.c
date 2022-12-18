#include<stdio.h>
#include<time.h>
#include<sys/time.h>
#include<sys/resource.h>
void selectionSort(int a[],int n)
{
    int min;
    int temp;
    for(int i=0;i<=n-2;i++)
    {
        min=i;
        for(int j=i+1;j<=n-1;j++)
        {
            if(a[min]>a[j])
                min=j;
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}
int main()
{
    int n,a[50];
    struct timeval tv1, tv2;
    struct rusage r;
    printf("Enter the no of elemnts:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
       gettimeofday(&tv1, NULL);
       selectionSort(a,n);
      gettimeofday(&tv2, NULL);
    for(int i=0; i<n; i++)
       {
       printf("%d",a[i]);
       }
    printf("\nt-->%f microseconds\n",(double)(tv2.tv_usec-tv1.tv_usec));
    getrusage(RUSAGE_SELF, &r);
     printf("%ld KB\n",r.ru_maxrss);
    printf("After sorting elements are:");
    for(int i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
    return 0;
}



