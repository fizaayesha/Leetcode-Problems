class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        bool vis=false;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j || i+j==n-1){
                    sum+=mat[i][j];
                }
            }
        }
        return sum;
    }
};