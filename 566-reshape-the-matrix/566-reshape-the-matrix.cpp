class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat,
                                      int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        int k=0,l=0;
        vector <vector <int>> ans(r,vector<int> (c));
        if(m*n!=r*c){
            return mat;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int e=mat[i][j];
                ans[k][l]=e;
                l++;
                if(l>=c){
                    k++;
                    l=0;
                }
            }
        }
        return ans;
    }
};