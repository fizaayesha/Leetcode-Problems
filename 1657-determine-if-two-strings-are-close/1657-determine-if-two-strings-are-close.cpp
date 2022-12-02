class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int n1 = word1.length(), n2 = word2.length();
        if (n1 != n2)
        {
            return false;
        }
        unordered_map<int, int> mp1, mp2;
        for (int i = 0; i < n1; i++)
        {
            mp1[word1[i]]++;
        }
        for (int i = 0; i < n2; i++)
        {
            mp2[word2[i]]++;
        }
        vector<int> v1, v2;
        vector<char> c1,c2;
        for (auto x : mp1)
        {
            v1.push_back(x.second);
            c1.push_back(x.first);
        }
        for (auto x : mp2)
        {
            v2.push_back(x.second);
            c2.push_back(x.first);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sort(c1.begin(),c1.end());
        sort(c2.begin(),c2.end());
        if(v1==v2 && c1==c2){
            return true;
        }
        return false;
    }
};