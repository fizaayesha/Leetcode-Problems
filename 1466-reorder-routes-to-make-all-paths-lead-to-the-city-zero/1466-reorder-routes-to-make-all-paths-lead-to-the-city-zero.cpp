class Solution {
public:
    vector<int> adj[50005];
    bool v[50005];
    set<pair<int,int>> s;
    int minReorder(int n, vector<vector<int>>& connections) {
        memset(v,false,sizeof(v));
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            s.insert({u,v});
        }
        queue<int> q;
        q.push(0);
        int total=0;
        while(!q.empty()){
            int k=q.front();
            q.pop();
            if(!v[k]){
                v[k]=true;
                for(int i=0;i<adj[k].size();i++){
                    q.push(adj[k][i]);
                    if(!v[adj[k][i]] && s.count({k,adj[k][i]})){
                        total++;
                    }
                }
            }
        }
        return total;
    }
};