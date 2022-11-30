class Solution
{
public:
    string replaceDigits(string s)
    {
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                s[i] = s[i];
            }
            else
            {
                s[i] = s[i] - '0' + s[i - 1];
            }
        }
        return s;
    }
};