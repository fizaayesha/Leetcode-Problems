class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        vector<pair<int, int>> p;
        int n = scores.size();
        for (int i = 0; i < n; i++)
        {
            p.push_back({ages[i], scores[i]});
        }
        sort(p.begin(), p.end());
        vector<int> dp(n,0);
        dp[0]=p[0].second;
        for (int i = 1; i < n; i++)
        {
            // cout << p[i].first << " " << p[i].second << endl;
            for (int j = 0; j < i; j++)
            {
                if (p[j].second <= p[i].second)
                {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += p[i].second;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
