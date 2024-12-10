class Solution {
public:
    bool dfsCycleElements(vector<bool> &parent, int node, vector<bool> &vis,vector<bool> &check, vector<vector<int>> &graph){
        vis[node]=true;
        parent[node]=true;
        check[node]=false;
        for(auto x:graph[node]){
            if(!vis[x]){
                if(dfsCycleElements(parent,x,vis,check,graph)) return true;
            }
            else if(parent[x]){
                return true;
            }
        }
        check[node]=true;
        parent[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> ans;
        vector<bool> check(V);
        vector<bool> parent(V);
        vector<bool> vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]) dfsCycleElements(parent,i,vis,check,graph);
        }
        for(int i=0;i<V;i++){
            if(check[i]==true){
                ans.push_back(i);
            }
        }
        return ans;
    }
};