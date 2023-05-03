class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                count++;
            }
            if(nums[i]==0){
                return 0;
            }
        }
        if(count==0 || count%2==0){
            return 1;
        }
        return -1;
    }
};