class Solution {
public:
    long long NEG=-100000000000000L;
    long long solve(int ind, int state, int n, vector<int> &nums,vector<vector<long long>> &dp){
        if(ind==n){
            return state==3?0:NEG;
        }
        if(dp[ind][state]!=-1LL){
            return dp[ind][state];
        }
        long long take=NEG,notTake=NEG;
        if(state==0){
            notTake=solve(ind+1,0,n,nums,dp);
        }
        if(state==3){
            take=nums[ind];
        }
        if(ind+1<n){
            if(state==0 && nums[ind+1]>nums[ind]){
                take=max(take,nums[ind]+solve(ind+1,1,n,nums,dp));
            }
            else if(state==1){
                if(nums[ind+1]>nums[ind]){
                    take=max(take,nums[ind]+solve(ind+1,1,n,nums,dp));
                }
                else if(nums[ind+1]<nums[ind]){
                    take=max(take,nums[ind]+solve(ind+1,2,n,nums,dp));
                }
            }
            else if(state==2){
                if(nums[ind+1]<nums[ind]){
                    take=max(take,nums[ind]+solve(ind+1,2,n,nums,dp));
                }
                else if(nums[ind+1]>nums[ind]){
                    take=max(take,nums[ind]+solve(ind+1,3,n,nums,dp));
                }
            }
            else if(state==3 && nums[ind+1]>nums[ind]){
                take=max(take,nums[ind]+solve(ind+1,3,n,nums,dp));
            }
        }
        return dp[ind][state]=max(take,notTake);
    }

    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(4,-1));
        return solve(0,0,n,nums,dp);
    }
};