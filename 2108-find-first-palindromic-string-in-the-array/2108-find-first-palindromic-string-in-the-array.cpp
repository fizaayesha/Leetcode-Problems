class Solution {
public:
    bool check(string s){
        string g = s; 
        reverse(g.begin(),g.end());
        if(g==s){
            return true;
        }
        return false;
    }
    string firstPalindrome(vector<string>& words) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            if(check(words[i])){
                ans.push_back(words[i]);
            }
        }
        if(ans.size()!=0){
            return ans[0];
        }
        return "";
    }
};