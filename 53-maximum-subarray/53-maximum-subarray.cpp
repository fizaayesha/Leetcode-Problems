class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=-1e6,sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            sum=max(sum,0);
        }
        return maxi;
    }
};