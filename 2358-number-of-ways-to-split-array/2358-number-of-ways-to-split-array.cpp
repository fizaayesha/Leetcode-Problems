class Solution {
public:
    int count=0;
    void solveMemoi(vector<int> &nums, int ind, int n, long long lH, long long rH, vector<int> &dp){
        if(ind==n-1){
            return;
        }
        if(dp[ind]!=-1){
            dp[ind]=count;
            return;
        }
        lH+=nums[ind];
        rH-=nums[ind];
        if(lH>=rH){
            count++;
            dp[ind]=count;
        }
        solveMemoi(nums,ind+1,n,lH,rH,dp);
    }
    //Recursive Approach----Accepted-O(N)->Runtime-1897ms, Beats-5.25%
    void solveRec(vector<int> &nums, int ind, int n,long long lH, long long rH){
        if(ind==n-1){
            return;
        }
        lH+=nums[ind];
        rH-=nums[ind];
        if(lH>=rH){
            cout<<lH<<" "<<rH<<endl;
            count++;
        }
        solveRec(nums,ind+1,n,lH,rH);
    }
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        count=0;
        long long lH=0LL;
        long long rH=accumulate(nums.begin(),nums.end(),0LL);
        cout<<rH<<endl;
        /*
        solveRec(nums,0,n,lH,rH);
        */
        vector<int> dp(n+1,-1);
        solveMemoi(nums,0,n,lH,rH,dp);
        return count;
    }
};