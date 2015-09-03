#include <stdio.h>

void swap(int *p,int *q) 
{
	int t=*p; *p=*q; *q=t;
}

int get_smallest_index(int a[],int start,int end)
{
	int small_index=start,i;
	
	for(i=start+1;i<=end;i++)
		if(a[i]<a[small_index])
		   small_index=i;

	return small_index;
}

void sort(int a[],int n)
{ 
  int i,smallest_index;

  for(i=0;i<n-1;i++) {
  	smallest_index=get_smallest_index(a,i+1,n-1);

	if(a[i]>a[smallest_index])
		swap(&a[i],&a[smallest_index]);
 }
}

main()
{
   int a[100],n,i;

   printf("Enter N "); scanf("%d",&n);

   printf("Enter data\n");
   for(i=0;i<n;i++) scanf("%d",&a[i]);

   sort(a,n);	

   printf("After sorting \n");
   for(i=0;i<n;i++) printf("%d\n",a[i]);
}
