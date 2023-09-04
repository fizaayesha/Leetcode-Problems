class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
            }
            else{
                count++;
            }
        }
        while(count--){
            ans.push_back(0);
        }
        nums=ans;
    }
};