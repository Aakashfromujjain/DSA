#include<stdio.h>
int MissingNo(int a[],int n){
	int x1=a[0];
	int x2=a[0];
	
	for(int i=1;i<n;i++)
		   x1=x1^a[i];
     for(int i=2;i<=n+1;i++)
     	   x2=x2^i;
     	   
 	   return(x1^x2);
}
int main()
{
	int a[5]={1,2,3,5,6};
	int n=sizeof (a)/sizeof (a[0]);
	int no=MissingNo(a,n);
	printf("%d",n);
	printf("missing = %d",no);
}
