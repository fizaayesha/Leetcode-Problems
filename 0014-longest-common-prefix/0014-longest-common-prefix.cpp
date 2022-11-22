class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if(n==1){
            return strs[0];
        }
        vector<string> ans;
        for (int i = 0; i < n - 1; i++)
        {
            string s1 = "";
            for (int j = 0; j < strs[i].size(); j++)
            {
                if (strs[i][j] != strs[i + 1][j])
                {
                    break;
                }
                s1 += strs[i][j];
            }
            ans.push_back(s1);
        }
        vector<pair<int, string>> v;
        for (int i = 0; i < ans.size(); i++)
        {
            v.push_back({ans[i].size(), ans[i]});
        }
        sort(v.begin(), v.end());
        if(v.size()==0){
            return "";
        }
        return v[0].second;
    }
};