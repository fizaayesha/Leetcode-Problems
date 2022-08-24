class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        int low=0, high=n, mid;
        while(low<=high){
            mid=low+(high-low)/2;
            int count=0;
            for(int i:nums){
                if(i>=mid){
                    count++;
                }
            }
            if(count==mid){
                return mid;
            }
            if(count>mid){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};