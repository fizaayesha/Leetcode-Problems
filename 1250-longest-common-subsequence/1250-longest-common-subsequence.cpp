class Solution {
public:
    int rec(string &s,string &t, int n, int m){
        if(n==0||m==0){
            return 0;
        }
        if(s[n-1]==t[m-1]){
            return 1+rec(s,t,n-1,m-1);
        }
        return max(rec(s,t,n,m-1),rec(s,t,n-1,m));
    }
    int memoi(string &s, string &t, int n, int m, vector<vector<int>> &dp){
        if(n==0 || m==0){
            return dp[n][m]=0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s[n-1]==t[m-1]){
            return dp[n][m]=1+memoi(s,t,n-1,m-1,dp);
        }
        return dp[n][m]=max(memoi(s,t,n,m-1,dp),memoi(s,t,n-1,m,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return memoi(text1,text2,n,m,dp);
    }
};