#include<stdio.h>
void swap(int *p,int *q) 
{
	int t=*p; *p=*q; *q=t;
}

void sort(int a[],int n)
{ int i,j,temp;
	
  for(i=0;i<n-1;i++)
  for(j=0;j<n-i-1;j++)
   if(a[j]>a[j+1])
   	  swap(&a[j],&a[j+1]);
}

main()
{
   int n,a[100],i;
   printf("Enter N "); scanf("%d",&n);
   printf("Enter data\n");
   for(i=0;i<n;i++) scanf("%d",&a[i]);
   sort(a,n);	
   printf("After sorting \n");
   for(i=0;i<n;i++) printf("%d\n",a[i]);
}
