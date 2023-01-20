class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> lis(n,1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[i][0] > pairs[j][1])
                {
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
        return *max_element(lis.begin(),lis.end());
    }
};
