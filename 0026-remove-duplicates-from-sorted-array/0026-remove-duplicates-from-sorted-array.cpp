class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int index=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                nums[index]=nums[i];
                index++;
            }
        }
        nums.erase(nums.begin()+index,nums.end());
        return nums.size();
    }
};