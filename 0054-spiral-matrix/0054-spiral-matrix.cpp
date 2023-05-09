class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> v;
        int n=matrix.size();
        int m=matrix[0].size();
        int minC=0;
        int minR=0;
        int maxR=n-1;
        int maxC=m-1;
        int count=0;
        int t=n*m;
        while(count<t){
            for(int j=minC;j<=maxC && count<t;j++){
                v.push_back(matrix[minR][j]);
                count++;
            }
            minR++;
            for(int i=minR;i<=maxR && count<t;i++){
                v.push_back(matrix[i][maxC]);
                count++;
            }
            maxC--;
            for(int j=maxC;j>=minC && count<t;j--){
                v.push_back(matrix[maxR][j]);
                count++;
            }
            maxR--;
            for(int i=maxR;i>=minR && count<t;i--){
                v.push_back(matrix[i][minC]);
                count++;
            }
            minC++;
        }
        return v;
    }
};