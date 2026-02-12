#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector <int> superior_elements(int arr[])
{
	vector<int> ans;
	int maxi=INT_MIN;
	int n=a.size();

	for(int i=n-1;i>=0;i--)
	{
		if(a[i]>maxi)
		{
           ans.push_back(a[i]):
		}
		maxi=max(maxi,a[i];
    }
	sort.

}
	int main()
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
		vector<int> a=superior_elements(arr);
		for(int i=0;i<n;i++) cout<<a[i]<<"  ";
		
		return 0;
	}
