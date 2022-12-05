class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            int res=0;
            int sum1=abs(points[i][0]-points[i+1][0]);
            int sum2=abs(points[i][1]-points[i+1][1]);
            res = max(sum1,sum2);
            ans+=res;
            
        }
        return ans;
        // vector<int> arr1;
        // vector<int> arr2;
        // for(int i=0;i<n;i++){
        //     arr1.push_back(points[0][i]);
        // }
        // for(int j=0;j<n;j++){
        //     arr2.push_back(points[1][j]);
        // }
        // int sum1=0,sum2=0;
        // for(int i=0;i<arr1.size()-1;i++){
        //     sum1+=abs(arr1[i+1]-arr1[i]);
        // }
        // for(int j=0;j<arr2.size()-1;j++){
        //     sum2+=abs(arr2[j+1]-arr2[j]);
        // }
    }
};