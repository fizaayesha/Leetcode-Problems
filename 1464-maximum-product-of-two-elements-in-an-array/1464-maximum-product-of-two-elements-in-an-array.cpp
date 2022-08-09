class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        int x=nums[0]-1;
        int y=nums[1]-1;
        return x*y;
    }
};