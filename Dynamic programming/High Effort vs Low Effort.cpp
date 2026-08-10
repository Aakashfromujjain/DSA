class Solution {
  public:
  
    int solve(int i, int prev, int n, vector<int>&h, vector<int>&l, vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        
        int no=solve(i+1, 0, n, h, l, dp);
        int lo=l[i]+solve(i+1, 1, n, h, l, dp);
        int hi=0;
        if(prev==0){
            hi=h[i]+solve(i+1, 1, n, h, l, dp);
        }
        return dp[i][prev]=max(no, max(lo, hi));
    }
  
    int maxTask(vector<int>& h, vector<int>& l) {
        // code here
        int n=h.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return solve(0, 0, n, h, l, dp);
    }
};
