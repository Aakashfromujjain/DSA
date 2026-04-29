// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            swap(s[i],swap[n-i-1]);
        }
        return s;
    }
};
