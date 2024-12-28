class Node{
    public:
    string key;
    double val;
    Node(string key, double val){
        this->key=key;
        this->val=val;
    }
};
class Solution {
public:
    unordered_map<string,vector<Node>> adj;
    void addEdge(vector<vector<string>>& equations, vector<double>& values){
        for(int i=0;i<values.size();i++){
            string src=equations[i][0];
            string dest=equations[i][1];
            // adj[src].push_back(Node(dest,values[i]));
            // adj[dest].push_back(Node(src,1/values[i]));
            adj[src].push_back({dest,values[i]});
            adj[dest].push_back({src,1/values[i]});
        }
    }
    double dfs(string src, string dest, unordered_set<string> &vis){
        if(adj.find(src)==adj.end() || adj.find(dest)==adj.end()){
            return -1.0;
        }
        if(src==dest){
            return 1.0;
        }
        vis.insert(src);
        for(Node &nd:adj[src]){
            if(vis.find(nd.key)==vis.end()){
                double ans=dfs(nd.key,dest,vis);
                if(ans!=-1.0){
                    return ans*nd.val;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans(queries.size());
        addEdge(equations,values);
        for(int i=0;i<queries.size();i++){
            string src=queries[i][0];
            string dest=queries[i][1];
            unordered_set<string> vis;
            ans[i]=dfs(src,dest,vis);
        }
        return ans;
    }
};