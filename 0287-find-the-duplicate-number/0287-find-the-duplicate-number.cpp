class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans;
        for(auto x: mp){
            if(x.second>=2){
                ans=x.first;
            }
        }
        return ans;
    }
};