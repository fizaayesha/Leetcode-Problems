class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char result;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        // cout<<s<<endl<<t<<endl;
        for (int i = 0; i < t.length(); i++)
        {
            if (s[i] != t[i])
            {
                return t[i];
            }
        }
        return t[t.length()-1];
    }
};