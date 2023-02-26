class Solution
{
public:
    vector<int> leftRigthDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftSum, rightSum;
        for (int i = 0; i < n; i++)
        {
            int leftS = 0, rightS = 0;
            for (int j = 0; j < i; j++)
            {
                leftS += nums[j];
            }
            for (int j = i + 1; j < n; j++)
            {
                rightS += nums[j];
            }
            leftSum.push_back(leftS);
            rightSum.push_back(rightS);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(abs(leftSum[i] - rightSum[i]));
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return ans;
    }
};