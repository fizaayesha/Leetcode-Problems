class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        if(n==0){
            return {};
        }
        if(n==1){
            return intervals;
        }
        int start=intervals[0][0];
        int end=intervals[0][1];
        int i=1;
        while(i<n){
            if(intervals[i][0]<=end){
                if(intervals[i][1]>end){
                    end=intervals[i][1];
                }
                i++;
            }
            else if(intervals[i][0]>end){
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
                i++;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};