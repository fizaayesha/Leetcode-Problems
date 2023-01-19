class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> output(k,0);
        int prefixModSum=0;
        int res=0;
        output[0]=1;
        for(int i=0;i<n;i++){
            prefixModSum=(prefixModSum+nums[i]%k+k)%k;
            res+=output[prefixModSum];
            output[prefixModSum]++;
        }
        return res;
    }
};