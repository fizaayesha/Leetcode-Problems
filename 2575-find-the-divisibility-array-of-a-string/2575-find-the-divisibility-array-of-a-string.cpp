class Solution
{
public:
    vector<int> divisibilityArray(string word, int m)
    {
        int n = word.length();
        string word1 = word;
        vector<int> arr;
        long long x = 0;
        for (int i = 0; i < n; i++)
        {
            x = x * 10 + (word[i]-'0');
            x%=m;
            if (x % m == 0)
            {
                arr.push_back(1);
            }
            else
            {
                arr.push_back(0);
            }
        }
        return arr;
    }
};