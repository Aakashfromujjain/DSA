#include <bits/stdc++.h>
using namespace std;

int demo(int x);
int main() {
	int n,f;
	cout<<"Enter the value of N:- ";
	cin>>n;
	f=demo(n);
	cout<<"\n Ans= "<<f;
}
int demo(int x)
{
	if(x==0){
		return 1;
	}else{
		return(x*demo(x-1));
	}
}
