class Solution {
public:
    static bool comp(pair<int,int> p, pair<int,int> q){
        if(p.first==q.first){
            return p.second>q.second;
        }
        return p.first<q.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> p;
        for(auto itr= mp.begin();itr!=mp.end();itr++){
            p.push_back({itr->second,itr->first});
        }
        sort(p.begin(),p.end(),comp);
        vector<int> arr;
        for(int i=0;i<p.size();i++){
            int count=p[i].first;
            while(count--){
                arr.push_back(p[i].second);
            }
        }
        return arr;
    }
};