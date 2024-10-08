class Solution {
public:
    void solve(vector<int> &candidates,int target, int start, vector<int> &demo, vector<vector<int>> &ans){
        if (accumulate(demo.begin(), demo.end(), 0) > target) {
            return;
        }
        if (accumulate(demo.begin(), demo.end(), 0) == target) {
            ans.push_back(demo);
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i-1]==candidates[i]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            demo.push_back(candidates[i]);
            solve(candidates,target,i,demo,ans);
            demo.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int start=0;
        vector<int> demo;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,start,demo,ans);
        return ans;
    }
};