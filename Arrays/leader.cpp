#include<bits/stdc++.h>
#include<iostream>
using namespace std;
vector<int> superior_elements(vector<int>&a)
{
	vector<int> ans;
	int maxi=INT_MIN;
	int n=a.size();

	for(int i=n-1;i>=0;i--)
	{
		if(a[i]>maxi)
		{
           ans.push_back(a[i]);
		}
		maxi=max(maxi,a[i]);
    }
	sort(ans.begin(),ans.end());
	return ans;
}
	int main()
	{
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++) cin>>arr[i];
		vector<int> a=superior_elements(arr);
		for(int i=0;i<a.size();i++) cout<<a[i]<<"  ";
		
		return 0;
	}
