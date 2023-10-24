class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
       sort(nums.begin(),nums.end());
        // nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    ++j;
                }
                else if(sum>0){
                    --k;
                }
                else{
                    vector<int> demo={nums[i],nums[j],nums[k]};
                    ans.push_back(demo);
                    ++j;
                    --k;
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                    while (j < k && nums[k] == nums[k + 1]) --k;

                }

            }
            
        }
        return ans;
    }
};