class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n2=nums.size();
        int unique=(n2/2)+1;
        unordered_map<int,int> mp;
        for(int i=0;i<n2;i++){
            mp[nums[i]]++;
        }
        int ans;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second==n2/2){
                ans=itr->first;
            }
        }
        return ans;
    }
};