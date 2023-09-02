class Solution
{
public:
    long long maxSum(vector<int> &nums, int m, int k)
    {
        int n = nums.size();
        long long maxSum = 0;
        unordered_map<int, int> freq;
        int uniqueCount = 0;

        for (int i = 0; i < k; i++)
        {
            if (freq[nums[i]] == 0)
            {
                uniqueCount++;
            }
            freq[nums[i]]++;
        }

        for (int i = k; i <= n; i++)
        {
            if (uniqueCount >= m)
            {
                long long sum = 0;
                for (int j = i - k; j < i; j++)
                {
                    sum += nums[j];
                }
                maxSum = max(maxSum, sum);
            }

            if (i == n)
            {
                break;
            }

            if (freq[nums[i - k]] == 1)
            {
                uniqueCount--;
            }
            freq[nums[i - k]]--;

            if (freq[nums[i]] == 0)
            {
                uniqueCount++;
            }
            freq[nums[i]]++;
        }

        return maxSum;
    }
};