class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int po=points[0][1];
        int count=1;
        sort(points.begin(),points.end());
        for(auto point:points){
            if(point[0]>po){
                count++;
                po=point[1];
            }
            po=min(point[1],po);
        }
        return count;
    }
};