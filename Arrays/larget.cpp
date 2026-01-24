#include<bits/stdc++.h>
using namespace std;
int largest(int arr[],int n) 
{
	int l=arr[0];
	for(int i=0;i<n;i++)
	{
		if(l<arr[i]) l=arr[i];
	}
	return l;
}
int main() 
{
	int n=6,arr[6]={3,2,6,55,-4,11};
	int l=largest(arr,n);
	cout<<"largest = "<<l;
	
}
