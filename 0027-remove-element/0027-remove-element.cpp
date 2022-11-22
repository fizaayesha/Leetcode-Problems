class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == val)
            {
                continue;
            }
            else
            {
                nums[index] = nums[i];
                index++;
            }
        }
        nums.erase(nums.begin() + index, nums.end());
        return nums.size();
    }
};
