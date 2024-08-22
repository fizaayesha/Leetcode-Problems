class Solution {
public:
    void solve(vector<int> &candidates,int target, vector<vector<int>> &ans,vector<int> &demo, int start){
        if(target==0){
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
            solve(candidates,target-candidates[i],ans,demo,i+1);
            demo.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> demo;
        int start=0;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,ans,demo,start);
        return ans;
    }
};
