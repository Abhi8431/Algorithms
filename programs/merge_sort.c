#include<stdio.h>
#include<time.h>
#include<sys/time.h>
#include<sys/resource.h>
void merge(int a[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int c[10000];
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=high)
        c[k++]=a[j++];
    for(int i=low;i<=high;i++)
        a[i]=c[i];
}
void mergeSort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
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
       mergeSort(a,0,n-1);
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


