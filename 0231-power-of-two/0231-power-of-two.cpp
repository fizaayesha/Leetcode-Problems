class Solution {
public:
    //Brute Force
    bool solveBrute(int n){
        for(int i=0;i<=30;i++){
            if(pow(2,i)==n){
                return true;
            }
        }
        return false;
    }
    //Getting TLE-Recursion
    bool solveRec(int ind, int n){
        if(ind>n){
            return false;
        }
        if(pow(2,ind)==n){
            return true;
        }
        return solveRec(ind+1,n);
    }
    //Memoization
    bool solveMemoi(int ind, int n, vector<int> &dp){
        if(pow(2,ind)>n){
            return false;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        if(pow(2,ind)==n){
            dp[ind]=true;
            return true;
        }
        dp[ind] = solveMemoi(ind+1,n,dp);
        return dp[ind];
    }
    //Tabulation
    bool solveTab(int n){
        if(n<=0){
            return false;
        }
        if(n==1){
            return true;
        }
        vector<int> dp(31,-1);
        dp[0]=1;
        for(int i=1;i<=30;i++){
            dp[i]=2*dp[i-1];
            if(dp[i]==n){
                return true;
            }
        }
        return false;
    }
    bool isPowerOfTwo(int n) {
        /*
        return solveRec(0,n);
        return solveBrute(n);
        if(n<=0) return false;
        vector<int> dp(31,-1);
        return solveMemoi(0,n,dp);
        */
        return solveTab(n);
    }
};