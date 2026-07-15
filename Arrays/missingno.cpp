#include<iostream>
using namespace std;

int main()
{
	int arr[5]={1,2,3,4,6};
	int n=5,flag=0;
	
	for(int i=1;i<=n;i++)
	{		flag=0;
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]==i){
		
			flag=i;
			break;
		}
		cout<<flag;
		}
	}
}
