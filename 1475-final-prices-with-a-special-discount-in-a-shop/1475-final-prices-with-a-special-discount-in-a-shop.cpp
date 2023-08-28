class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());
        int n=prices.size();
        for(int i=0;i<n;i++){
            if (ans.size() - 1 == i)
                {
                    ans[i] = prices[i];
                    break;
                }
            for(int j=i+1;j<n;j++){
                if(prices[i]>=prices[j]){
                    ans[i]=prices[i]-prices[j];
                    break;
                }
                else{
                    ans[i]=prices[i];
                }
            }
        }
        return ans;
    }
};