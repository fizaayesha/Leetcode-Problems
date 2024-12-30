class Solution {
public:
    //Recursion
    void recursionApp(vector<int> &prices, int mini, int &maxi, int ind, int n){
        if(ind==n){
            return;
        }
        mini=min(prices[ind],mini);
        int profit=prices[ind]-mini;
        maxi=max(maxi,profit);
        recursionApp(prices,mini,maxi,ind+1,n);
    }
    //O(n) Approach
    int maxProfit(vector<int>& prices) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        /*
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            int profit=prices[i]-mini;
            maxi=max(maxi,profit);
        }
        */
        int n=prices.size();
        recursionApp(prices,mini,maxi,0,n);
        return maxi;
    }
};