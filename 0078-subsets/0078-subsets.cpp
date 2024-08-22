class Solution {
public:
    void solve(vector<int> &nums, vector<int> &demo, int start,vector<vector<int>> &ans){
        int n = nums.size();
        ans.push_back(demo);
        for(int i=start;i<n;i++){
            if(i>start && nums[i-1]==nums[i]){
                continue;
            }
            demo.push_back(nums[i]);
            solve(nums,demo,i+1,ans);
            demo.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> demo;
        sort(nums.begin(),nums.end());
        solve(nums,demo,0,ans);
        return ans;
    }
};