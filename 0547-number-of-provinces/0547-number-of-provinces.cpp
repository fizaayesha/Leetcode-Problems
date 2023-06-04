class Solution {
public:
void soln(vector<int>adj[],int node,vector<bool>&vis){
    vis[node] = 1;
    for(auto i:adj[node]){
        if(!vis[i]){
            soln(adj,i,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n,0);
        int ans= 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                soln(adj,i,vis);
                ans++;
            }
        }
        return ans;
    }
};
