#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void Removezero(int arr[],int n)
{
vector<int> temp;
//step[1]
for(int i=0;i<n;i++)
{
	if(arr[i]!=0)
	{
		temp.push_back(arr[i]);
	}
}
//step[2]
int nz=temp.size();
for(int i=0;i<nz;i++)
{
	arr[i]=temp[i];
}
//step[3]
for(int i=nz;i<n;i++)
{
	arr[i]=0;
}
}

	int main()
	{
		int n=10;
		int arr[n]={1,0,2,0,0,5,9,0,3,0};
		Removezero(arr, n);
		for(int i=0;i<n;i++)
		{
			cout<<arr[i]<<"  ";
		}
		return 0;
	}
