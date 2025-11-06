class Solution {
public:
    bool solve(string s, vector<string> &word, int n){
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                string str=s.substr(j,i-j);
                if(dp[j] && find(word.begin(),word.end(),str)!=word.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s,wordDict,s.length());
    }
};
