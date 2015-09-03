#include<stdio.h>

int a[100];

void swap(int *p,int *q) 
{
	int t=*p; *p=*q; *q=t;
}

void split(int low,int high,int *partition)
{
 int pivot,i,j;
  
	pivot = a[low] ;
	i = low ;
	j = high ;

	while (i<j )
	{
	  while ( a[i] <= pivot  &&  i < j ) 
				i++;
	  while ( a[j] > pivot )   
				j--;

		if ( i < j )
			swap(&a[i],&a[j]);
	}
	
	*partition = j ;
	swap(&a[low],&a[j]);
}

void quick(int low,int high)
{
	int partition;
	if (low<high )
	{ 	split (low,high,&partition) ;
		quick (low,partition-1) ;
		quick (partition+1,high) ;
	}
}

main()
{
   int n,i;
   printf("Enter N "); scanf("%d",&n);

   printf("Enter data\n");
   for(i=0;i<n;i++) scanf("%d",&a[i]);

   quick(0,n-1);	

   printf("After sorting \n");
   for(i=0;i<n;i++) printf("%d\n",a[i]);
}
