class Solution {
public:
    void binaryS(vector<int> &nums, int n, int target, int multiplier){
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                nums[mid]*=multiplier;
                return;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
    }
    void linaearS(vector<int> &nums, int n, int target, int multiplier){
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                nums[i]*=multiplier;
                break;
            }
        }
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        while(k--){
            int mini=*min_element(nums.begin(),nums.end());
            linaearS(nums,n,mini,multiplier);
        }
        return nums;
    }
};