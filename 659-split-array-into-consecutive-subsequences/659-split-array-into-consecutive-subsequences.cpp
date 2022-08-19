class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map <int,int> freq;
        for(int i: nums){
            freq[i]++;
        }
        unordered_map <int,int> subLast;
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]==0){
                continue;
            }
            if(subLast[nums[i]-1]>0){
                freq[nums[i]]--;
                subLast[nums[i]-1]--;
                subLast[nums[i]]++;
            }
            else if(freq[nums[i]+1]>0 && freq[nums[i]+2]>0){
                freq[nums[i]]--;
                freq[nums[i]+1]--;
                freq[nums[i]+2]--;
                subLast[nums[i]+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};