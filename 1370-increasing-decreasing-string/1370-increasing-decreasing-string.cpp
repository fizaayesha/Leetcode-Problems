class Solution {
public:
    string sortString(string s) {
        string ans="";
        int n=s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        bool found=true;
        while(found){
            found=false;
            for(char ch='a';ch<='z';ch++){
                if(mp[ch]){
                    ans.push_back(ch);
                    mp[ch]--;
                    found=true;
                }
            }
            for(char ch ='z';ch>='a';ch--){
                if(mp[ch]){
                    ans.push_back(ch);
                    mp[ch]--;
                    found=true;
                }
            }
        }
        return ans;
    }
};