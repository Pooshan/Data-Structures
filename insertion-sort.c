#include<stdio.h>

void sort(int a[],int n)
{ int i,j,k,temp;

  for(i=1;i<n;i++)
  {
    for(j=0;j<i;j++)
    if(a[j]>a[i])
      {
		 temp=a[i];
			 for(k=i;k>j;k--)
			  a[k]=a[k-1];
		 a[k]=temp;
      }
  }
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
