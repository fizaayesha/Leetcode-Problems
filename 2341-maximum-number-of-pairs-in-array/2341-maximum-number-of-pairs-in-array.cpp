class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int one = 0, two = 0;
        for (auto x : mp)
        {
            one += x.second / 2;
            two += x.second % 2;
        }
        return {one,two};
    }
};