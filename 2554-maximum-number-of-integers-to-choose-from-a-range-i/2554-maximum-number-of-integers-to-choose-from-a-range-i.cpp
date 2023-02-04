class Solution {
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        int ans = 0,sum=0;
        unordered_set<int> v(banned.begin(), banned.end());
        for (int j = 1; j <=n; j++)
        {
            if(v.count(j)==0){
                if(sum+j<=maxSum){
                    sum+=j;
                    ans++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};