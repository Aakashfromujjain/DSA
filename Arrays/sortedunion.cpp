#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
vector < int > sortedunion(vector <int>a,vector <int>b)
{
	set<int> st;
	for(int i=0;i<a.size();i++)
	{
		st.insert(a[i]);
	}
	for(int i=0;i<b.size();i++)
	{
		st.insert(b[i]);
	}
	
	vector<int>newa;
	
	for(auto it:st)
	 	    newa.push_back(it);

	return newa;	    
}


int main()
{
	vector<int> arr1={1,2,3,4,5,6,9};
	vector<int> arr2={5,8,99};
	vector<int> t;
	t=sortedunion(arr1,arr2);
	for (int it:t)
	cout<<it<<"	";
	return 0;
	}
