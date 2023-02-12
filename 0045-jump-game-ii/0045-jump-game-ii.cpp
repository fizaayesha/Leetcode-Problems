class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int curr=0,jump=0,maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(i+nums[i]>maxi){
                maxi=i+nums[i];
            }
            if(i==curr){
                jump++;
                curr=maxi;
            }
        }
        return jump;
    }
};