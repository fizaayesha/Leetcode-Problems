class Solution {
public:
    int solve(vector<int> &arr, int n, int target, vector<vector<int>> &dp){
        if(n==0)  return false;
        if(target==0) return true;
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        if(arr[n-1]<=target){
           dp[n][target]= solve(arr,n-1,target-arr[n-1],dp) || solve(arr,n-1,target,dp);
        }
        else{
            dp[n][target]=solve(arr,n-1,target,dp);
        }
        return dp[n][target];
    }
    bool canPartition(vector<int> &arr){
        int n=arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%2!=0)return false;
        int target=sum/2;
        vector<vector<int>> dp(n+1,(vector<int>(target+1,-1)));
        return solve(arr,n,target,dp);
    }
};