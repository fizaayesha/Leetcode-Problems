class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        queue<pair<int, pair<int,int>>> q;
        int qx[] = {1,-1,0,0};
        int qy[] = {0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            pair<int,pair<int,int>> p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newx = p.second.first+qx[i];
                int newy = p.second.second+qy[i];
                if (newx<n && newy<m && newx>=0 && newy>=0){
                    if(mat[newx][newy]==1){
                        if(ans[newx][newy]>p.first+1){
                            ans[newx][newy] = p.first+1;
                            q.push({p.first+1,{newx,newy}});
                        }
                    }
                }                
            }
        }
        return ans;
    }
};