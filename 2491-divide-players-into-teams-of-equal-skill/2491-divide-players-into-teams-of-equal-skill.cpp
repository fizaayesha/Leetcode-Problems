class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(),skill.end());
        int start=0,end=n-1;
        vector<long long> t;
        vector<pair<long long,long long>> p;
        while(start<=end){
            p.push_back({skill[start],skill[end]});
            t.push_back(skill[start]+skill[end]);
            start++;
            end--;
        }
        long long pro=0;
        unordered_map<long long,int> mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
        }
        if(mp.size()>1){
            return -1;
        }
        else{
            for(int i=0;i<p.size();i++){
                pro+=(p[i].first*p[i].second);
            }
        }
        return pro;
    }
};