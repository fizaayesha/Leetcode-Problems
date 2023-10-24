class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int ans=0;
        unordered_map<char,int> mp;
        int count=0;
        int i=0;
        for(int j=0;j<n;j++){
            while(mp[s[j]]){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            mp[s[j]]++;
        }
        return ans;
    }
};