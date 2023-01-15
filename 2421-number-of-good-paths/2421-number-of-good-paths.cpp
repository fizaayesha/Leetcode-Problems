class DSU {
    public:
    vector<int> rank;
    vector<int> parent;
    DSU(int n){
        rank.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++){
            rank[i]=0;
            parent[i]=i;
        }
    }
    int findParent(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=findParent(parent[x]);
    }
    void makeUnion(int x, int y){
        int p1=findParent(x);
        int p2=findParent(y);
        if(p1!=p2){
            if(rank[p1]>rank[p2]){
                parent[p2]=p1;
                rank[p1]=rank[p2];
            }
            else{
                parent[p1]=p2;
                rank[p2]+=rank[p1];
            }
        }
    }
};
class Solution{
    public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<int> adj[n];
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        map<int,vector<int>> valToNode;
        for(int i=0;i<n;i++){
            valToNode[vals[i]].push_back(i);
        }
        DSU dsu(n);
        int res=0;
        for(auto [val,nodes]:valToNode){
            for(auto node:nodes){
                for(auto neighbour:adj[node]){
                    if(vals[neighbour]<=vals[node]){
                        dsu.makeUnion(node,neighbour);
                    }
                }
            }
            unordered_map<int,int> pf;
            for(auto node: nodes){
                pf[dsu.findParent(node)]++;
            }
            for(auto it:pf){
                int cnt=(it.second*(it.second+1))/2;
                res+=cnt;
            }
        }
        return res;
    }
};