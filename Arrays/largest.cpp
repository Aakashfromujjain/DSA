#include<bits/stdc++.h>
using namespace std;
int largest(vector<int> &arr,int n) 
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
	int n=6;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int result=largest(arr,n);
	cout<<"largest = "<<result;
	
}
