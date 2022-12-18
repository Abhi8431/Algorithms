#include<stdio.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>
#include<stdlib.h>
#include<sys/resource.h>

int board[20], count;

int place(int row, int column)
{
	int i;
	for(i=1; i<=row-1; ++i)//until row-1
	{
		if(board[i] == column)
			return 0;
		else if(abs(board[i]-column) == abs(i-row))
			return 0;
	}
	return 1;
}

void print(int n)
{
	printf("\n\nSolution %d\n\n", ++count);
	
	for(int i=1; i<=n; i++)
	    printf("\t%d",i);
	    
	for(int i=1; i<=n; i++)
	{
	    printf("\n\n%d",i);
		for(int j=1; j<=n; j++)
		{
			if(j == board[i])
				printf("\tQ");
			else
				printf("\t-");
		}
	}
}

void queen(int row, int n)
{
	for(int column=1; column<=n; column++)
	{
		if(place(row, column))
		{
			board[row] = column;
			if(row == n)
				print(n);
			else
				queen(row+1, n);
		}
	}
}

void main()
{
    
    int n;
    struct timeval tv1, tv2;
    struct rusage r;
    printf("n--> ");
    scanf("%d", &n);
    gettimeofday(&tv1, NULL);
    queen(1,n);
    gettimeofday(&tv2, NULL);
   
    printf("\nt-->%f microseconds\n",(double)(tv2.tv_usec-tv1.tv_usec));
    getrusage(RUSAGE_SELF, &r);
    printf("%ld KB\n",r.ru_maxrss);
    printf("output:");
}

