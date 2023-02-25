class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min=INT_MAX;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(min>prices[i]){
                min=prices[i];
            }
            int x=prices[i]-min;
            ans=max(x,ans);
        }
        return ans;
    }
};