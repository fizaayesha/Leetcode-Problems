class Solution {
public:
    int solveRec(string s, int ind, int n, vector<int> &dp){
        if(ind==n){
            return 1;
        }
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int count=solveRec(s,ind+1,n,dp);
        if(ind+1<n){
            int num=stoi(s.substr(ind,2));
            if(num>=10 && num<=26){
                count+=solveRec(s,ind+2,n,dp);
            }
        }
        dp[ind]=count;
        return count;
    }
    //Tabulation
    int solveTab(string s, int n){
        vector<int> dp(n+1,0);
        if(n==0 || s[0]=='0'){
            return 0;
        }
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }
            int num=stoi(s.substr(i-2,2));
            if(num>=10 && num<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
    int numDecodings(string s) {
        int n=s.length();
        /*
        if(n==0) return 0;
        int ind=0;
        vector<int> dp(n+1,-1);
        return solveRec(s,ind,n,dp);
        */
        return solveTab(s,n);
    }
};