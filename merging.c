#include<stdio.h>
//implementation of merging
main()
{
  int a[10],b[10],c[20],i,j,k,m,n;

  printf("Array-A size?: ");
  scanf("%d",&m);
  printf("Array-B size?: ");
  scanf("%d",&n);

  printf("enter elements-A\n");
  for(i=0;i<m;i++)
   scanf("%d",&a[i]);

  printf("enter elements-B\n");
  for(j=0;j<n;j++)
   scanf("%d",&b[j]);

 for(k=0,i=0,j=0;i<m && j<n;k++)
  if(a[i]<b[j])
   {
    c[k]=a[i];
    i++;
   }
   else
   {
    c[k]=b[j];
    j++;
   }

   while(i<m)   c[k++]=a[i++];
   while(j<n)   c[k++]=b[j++];

  printf("elements of array-C\n");
  for(i=0;i<m+n;i++)
  printf("%d\n",c[i]);
}
