class Solution {
public:
    void solve(vector<int> &candidates, int target, int start, int end, vector<int> demo, vector<vector<int>> &ans){
        if(accumulate(demo.begin(),demo.end(),0)==target){
            ans.push_back(demo);
            return;
        }
        if(accumulate(demo.begin(),demo.end(),0)>target){
            return;
        }
        for(int i=start;i<end;i++){
            demo.push_back(candidates[i]);
            solve(candidates,target,i,end,demo,ans);
            demo.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> demo;
        vector<vector<int>> ans;

        solve(candidates,target,0,candidates.size(),demo,ans);
        return ans;
    }
};