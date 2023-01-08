class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=1;
        for(int i=0;i<n;i++){
            unordered_map<double,int> mp;
            for(int j=i+1;j<n;j++){
                if(points[i][0]==points[j][0]){
                    mp[10000001]++;
                }
                else{
                    double slope = (double)(points[i][1]-points[j][1])/(double)(points[i][0]-points[j][0]);
                    mp[slope]++;
                }
            }
            int maxi=0;
            for(auto itr: mp){
                if(itr.second>maxi){
                    maxi=itr.second;
                }
            }
            ans=max(maxi+1,ans);
        }
        return ans;
    }
};