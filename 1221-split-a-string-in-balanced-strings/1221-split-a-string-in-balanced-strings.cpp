class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int n = s.length();
        unordered_map<int, char> mp;
        set<int> st;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            st.insert(s[i]);
            mp[s[i]]++;
            if (st.size() == 2 && mp['L'] == mp['R'])
            {
                mp.clear();
                st.clear();
                count++;
            }
        }
        return count;
    }
};