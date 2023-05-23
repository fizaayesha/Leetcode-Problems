class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> res;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> p;
        for(auto i:mp){
            p.push(make_pair(i.second,i.first));
        }
        for(int i=0;i<k;i++){
            res.push_back(p.top().second);
            p.pop();
        }
        return res;
    }
};