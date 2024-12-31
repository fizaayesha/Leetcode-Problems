class Solution {
public:
    int tabu(int n){
        vector<int> dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        if(n<=1){
            return dp[n];
        }
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int memoi(int n, vector<int>& dp) {
        if (n <= 1) return 1;
        if (dp[n] != -1) {
            return dp[n];
        }
        dp[n] = memoi(n - 1, dp) + memoi(n - 2, dp);
        return dp[n];
    }
    int solve(int n){
        if(n<=1){
            return 1;
        }
        else{
            return solve(n-1)+solve(n-2);
        }
        return solve(n);
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        return tabu(n);
    }
};