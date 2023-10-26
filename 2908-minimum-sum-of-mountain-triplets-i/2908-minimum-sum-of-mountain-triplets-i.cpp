class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i<j && j<k){
                        if(nums[i]<nums[j] && nums[k]<nums[j]){
                            ans = min(ans,nums[i]+nums[j]+nums[k]);
                        }
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};