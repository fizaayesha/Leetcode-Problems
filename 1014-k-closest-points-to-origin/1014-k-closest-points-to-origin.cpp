class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            int sqr = (points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            pq.push({sqr,{points[i][0],points[i][1]}});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};