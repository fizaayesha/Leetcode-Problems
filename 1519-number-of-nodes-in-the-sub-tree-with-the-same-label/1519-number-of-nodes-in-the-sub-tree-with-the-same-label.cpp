class Solution {
public:
    vector<int> ans;
    vector<vector<int>> graph;
    vector<int> dfs(int s, int parent, string &labels){
        vector<int> res(26,0);
        res[labels[s]-'a']++;
        for(int it: graph[s]){
            if(it==parent){
                continue;
            }
            vector<int> f = dfs(it, s, labels);
            for(int i=0;i<26;i++){
                res[i]+=f[i];
            }
        }
        ans[s]=res[labels[s]-'a'];
        return res;
    }
    vector<int> countSubTrees(int n, vector<vector<int>> &edges,string labels){
        ans.resize(n,0);
        graph.resize(n,vector<int>{});
        for(auto itr:edges){
            graph[itr[0]].push_back(itr[1]);
            graph[itr[1]].push_back(itr[0]);
        }
        dfs(0,-1,labels);
        return ans;
    }
};