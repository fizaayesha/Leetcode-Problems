class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(prices[i],mini);
            int x=prices[i]-mini;
            profit=max(profit,x);
        }
        return profit;
    }
};