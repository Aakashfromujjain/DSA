#include<bits/stdc++.h>
using namespace std;

vector<int> rotater(vector<int> &arr,int n)
{
	int temp=arr[0];
	for(int i=1;i<n;i++)
	{
		arr[i-1]=arr[i];
	}
	arr[n-1]=temp;
	return arr;
}
int main()
{
	int n=9,i;
	vector<int> arr={1,2,3,4,5,6,7,8,9};
	rotater(arr,n);
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}
