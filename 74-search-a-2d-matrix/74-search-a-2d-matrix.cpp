class Solution {
public:
        // int n=matrix.size();
        // int m=matrix[0].size();
        // int t=n*m;
        // int low1=0;
        // int high1=t-1;
        // int mid1=low1+(high1-low1)/2;
        // while(low1<=high1){
        //     if(matrix[mid1/m][mid1%m]==target){
        //         return 1;
        //     }
        //     else if(matrix[mid1/m][mid1%m]>target){
        //         high1=mid1-1;
        //     }
        //     else{
        //         low1=mid1+1;
        //     }
        //     mid1=low1+(high1-low1)/2;
        // }
        // return 0;

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m=matrix[0].size();
        int t=n*m;
        int low=0;
        int high=t-1;
        int mid=low+(high-low)/2;
        while(low<=high){
            if(matrix[mid/m][mid%m]==target){
                return 1;
            }
            else if(matrix[mid/m][mid%m]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        return 0;
    }
};