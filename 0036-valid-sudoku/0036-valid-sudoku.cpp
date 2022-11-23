class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        map<int, map<int, int>> row;
        map<int, map<int, int>> column;
        map<pair<int,int>, map<int,int>> box;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!='.'){
                    if(row[i][board[i][j]] || column[j][board[i][j]] || box[{i/3,j/3}][board[i][j]]){
                        return false;
                    }
                    row[i][board[i][j]]++;
                    column[j][board[i][j]]++;
                    box[{i/3,j/3}][board[i][j]]++;
                }
            }
        }
        return true;
    }
};