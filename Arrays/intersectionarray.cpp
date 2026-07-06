#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
vector < int > arrayintersection(vector <int>&a,int n,vector <int>&b,int m)
{
	int i=0;
	int j=0;	    
	vector<int> ans;
	while(i<n && j<m)
	{
		if(a[i] <b[j]) {
			i++;
	}else if(b[j] <a[i]){
		j++;
	}
	else	{
		ans.push_back(a[i]);
		i++;
		j++;
		}
	}
	return ans;
}


int main()
{
	vector<int> arr1={1,2,3,4,5,6,9};
	vector<int> arr2={5,8,99};
	vector<int> t;
	t=arrayintersection(arr1,arr1.size(),arr2,arr2.size());
	for (int it:t)
	cout<<it<<"	";
	return 0;
	}
