class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int n, int dash, int k){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        for(int i=dash;i<=n;i++){
            temp.push_back(i);
            solve(ans,temp,n,i+1,k-1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,n,1,k);
        return ans;
    }
};