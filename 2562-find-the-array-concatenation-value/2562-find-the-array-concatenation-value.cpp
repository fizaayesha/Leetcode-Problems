class Solution
{
public:
    int concat(int a, int b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        string s = s1 + s2;
        int c = stoi(s);
        return c;
    }
    long long findTheArrayConcVal(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        int start = 0, end = n - 1;
        while (start < end)
        {
            int x = concat(nums[start], nums[end]);
            ans += x;
            start++;
            end--;
        }
        if (n % 2 != 0)
        {
            ans += nums[n / 2];
        }
        return ans;
    }
};