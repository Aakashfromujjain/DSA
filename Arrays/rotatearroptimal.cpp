#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void LeftRotate(int arr[],int n,int d)
{
	d=d%n;

	int temp[d];
	for(int i=0;i<d;i++)
	{
		temp[i]=arr[i];
	}
	for(int i=d;i<n;i++)
	{
		arr[i-d]=arr[i];
	}
	for(int i=n-d;i<n;i++)
	{
		arr[i]=temp[i-(n-d)];
	}
for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
	cout<<endl;
	for(int i=0;i<d;i++)
	{
		cout<<temp[i]<<"  ";
	}

}
	int main()
	{
		int n;
		cin>>n;
		int d;
		cin>>d;
		int arr[7]={11,22,33,44,55,6,77};
		LeftRotate(arr,n,d);
		return 0;
	}
