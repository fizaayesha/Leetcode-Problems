class Solution {
public:
    bool solveRec(string s, vector<string>& wordDict, int ind, int n, vector<int> &dp){
        if(ind==n){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        string str="";
        for(int i=ind;i<n;i++){
            str+=s[i];
            cout<<str<<" ";
            if(find(wordDict.begin(),wordDict.end(),str) != wordDict.end()){
                if(solveRec(s,wordDict,i+1,n,dp)){
                    return dp[ind]=true;
                }
            }
            cout<<endl;
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1,-1);
        return solveRec(s,wordDict,0,s.length(),dp);
    }
};