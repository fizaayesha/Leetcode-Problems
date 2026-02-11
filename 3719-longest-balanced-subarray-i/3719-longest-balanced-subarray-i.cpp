class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            set<int> evenFreq, oddFreq;
            for(int j=i;j<n;j++){
                if(nums[j]%2){
                    oddFreq.insert(nums[j]);
                }
                else{
                    evenFreq.insert(nums[j]);
                }
                if(evenFreq.size()==oddFreq.size()){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};
