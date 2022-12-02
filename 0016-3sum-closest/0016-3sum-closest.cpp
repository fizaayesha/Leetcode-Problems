class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int currSum=nums[i]+nums[j]+nums[k];
                if(abs(currSum-target)<abs(ans-target)){
                    ans=currSum;
                }
                if(currSum<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};