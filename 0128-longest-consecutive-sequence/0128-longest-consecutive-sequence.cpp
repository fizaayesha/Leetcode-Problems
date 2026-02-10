class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int maxi=0;
        for(auto x:nums){
            mp[x]=1;
        }
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(mp.find(x)!=mp.end() && mp.find(x-1)==mp.end()){
                int curr=x;
                int count=0;
                while(mp.find(curr)!=mp.end()){
                    mp.erase(curr);
                    curr++;
                    count++;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};