#include<iostream>
#include<string>
#include<algorithm>  //For swap
using namespace std;
void permute(string s,int l,int r) {
	//Base case: if all characters have been placed
	if(l==r){
		cout<<s<<endl;
	}else{
	
		for(int i=l;i<=r;i++) {
		//swap current character with character at index 1
		swap(s[l],s[i]);
		
		//Recursively call for the rest of the string
		permute(s,l+1,r);
		
		//backtrack swap back to restore original order
		swap(s[l],s[i]);
	}
}
}

int main() {
	string str;
	cin>>str;
	int n=str.length();
	permute(str,0,n-1);
	return 0;
}
