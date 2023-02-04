class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        // 1 2 2 3 3 4 7 8
        vector<int> res;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp[i + 1] == 0)
            {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
