#include<iostream>
using namespace std;

void twosum(int *arr,int n,int target)
{
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		
			if(arr[i]+arr[j]==target)
			{
   			     cout<<"  "<<i<<"   "<<j;
			}
		}
		
	}
}
int main()
{
	int n=6,target=14;
	int arr[n]={2,4,9,7,10,25};
	twosum(arr,n,target);
	return 0;
}
