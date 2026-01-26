#include<bits/stdc++.h>
using namespace std;
int secondlargest(vector<int> &arr,int n);
int secondsmallest(vector<int> &arr,int n);
int main()
{
	int n;
	cout<<"Enter the size: ";
	cin>>n;
	cout<<"Enter the elements: ";
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"The second largest is = "<<secondlargest(arr,n)<<endl;
	cout<<"The second smallest is = "<<secondsmallest(arr,n);
	return 0;
}

int secondlargest(vector<int> &arr,int n)
{
	int largest=arr[0];
	int slargest= -1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>largest)
		{
			slargest=largest;
			largest=arr[i];
		}
		else if(arr[i]<largest && arr[i]>slargest)
		{
			slargest=arr[i];
		}
	}
	return slargest;
}
int secondsmallest(vector<int> &arr, int n){
	int smallest =arr[0];
	int secondsmall=INT_MAX;
	for(int i=1;i<n;i++)
	{
		if(arr[i]<smallest)
		{
			secondsmall=smallest;
			smallest=arr[i];
		}
		else if(arr[i]!=smallest && arr[i]<secondsmall)
		{
			secondsmall=arr[i];
		}
	return secondsmall;
	}
}
