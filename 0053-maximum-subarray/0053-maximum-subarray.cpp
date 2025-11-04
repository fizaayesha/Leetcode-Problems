class Solution {
public:
    int solveBrute(vector<int> &nums, int n){
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(sum<0){
                sum=0;
            }
            sum+=nums[i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
    int maxi=INT_MIN;
    void solveRec(vector<int> &nums,int n, int ind, int sum){
        if(ind==n){
            return;
        }
        if(sum<0){
            sum=0;
        }
        sum+=nums[ind];
        maxi=max(maxi,sum);
        solveRec(nums,n,ind+1,sum);
    }
    void solveMemoi(vector<int> &nums, int n, int ind, int sum, vector<int> &dp){
        if(ind==n) return;
        if(dp[ind]!=-1){
            return;
        }
        if(sum<0){
            sum=0;
        }
        sum+=nums[ind];
        maxi=max(maxi,sum);
        dp[ind]=maxi;
        solveMemoi(nums,n,ind+1,sum,dp);
    }
    int solveTab(vector<int> &nums, int n){
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+nums[i];
            if(dp[i]<nums[i]){
                dp[i]=nums[i];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        /*
        vector<int> dp(n+1,-1);
        solveMemoi(nums,n,0,0,dp);
        return maxi;
        return solveBrute(nums,n);
        */
        return solveTab(nums,n);
    }
};