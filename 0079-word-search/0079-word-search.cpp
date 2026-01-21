class Solution {
public:
    bool found=false;
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int i, int j, int n, int m, vector<vector<bool>> &vis){
        return i>=0 && j>=0 && i<n && j<m && !vis[i][j];
    }
    void solve(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<char>>& board, string &word, int ind){
        if(found){
            return;
        }
        if (board[i][j] != word[ind]) return;
        if(!isSafe(i,j,n,m,vis)){
            return;
        }
        if (ind == word.size() - 1) { // last char matched
            found = true;
            return;
        }
        // cout<<"1 call"<<endl;
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            // cout<<"2 call"<<endl;
            int newI=i+dir[k].first;
            int newJ=j+dir[k].second;
            if(isSafe(newI,newJ,n,m,vis)){
                solve(newI,newJ,n,m,vis,board,word,ind+1);
            }
        }
        vis[i][j]=false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        int i=0,j=0,ind=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve(i, j, n, m, vis, board, word, 0);
                if (found) return true;
            }
        }
        return false;
    }
};