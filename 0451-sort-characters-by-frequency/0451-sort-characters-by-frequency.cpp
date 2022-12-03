class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int, char>> p;
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            p.push_back({itr->second, itr->first});
        }
        sort(p.begin(), p.end());
        reverse(p.begin(), p.end());
        string ans = "";
        for (int i = 0; i < p.size(); i++)
        {
            int count = p[i].first;
            while (count--)
            {
                ans.push_back(p[i].second);
            }
        }
        // cout << ans;
        return ans;
    }
};