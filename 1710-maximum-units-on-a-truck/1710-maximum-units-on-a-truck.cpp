class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int n = boxTypes.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i].first = boxTypes[i][1];
            v[i].second = boxTypes[i][0];
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cout << v[i].first << " " << v[i].second << endl;
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i].first << " " << v[i].second << endl;
            int numberOfBoxes = min(truckSize, v[i].second);
            ans += (numberOfBoxes * v[i].first);
            truckSize -= numberOfBoxes;
        }
        return ans;
    }
};