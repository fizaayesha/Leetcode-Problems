class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int start=0,end=(n*m)-1;
        int mid=start+(end-start)/2;
        while(start<=end){
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            else if(target>matrix[mid/m][mid%m]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
          mid=start+(end-start)/2;  
        }
        return false;
    }
};