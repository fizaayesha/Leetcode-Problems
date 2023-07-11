class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int t2=target;
        int n=nums.size();
        int t1=target*(-1);
        vector<int> dp(n,-1);
        dp[0]=0;
        // int start=0;
        // int end=n-1;
//         while(start<=end){
            
//         }
        for(int i=0;i<n;i++){
            if(dp[i]==-1) continue;
            for(int j=i+1;j<n;j++){
                if(nums[j]-nums[i]>=t1 && nums[j]-nums[i]<=t2){
                    dp[j]=max(dp[i]+1,dp[j]);
                }
            }
        }
        return dp[n-1];
    }
};