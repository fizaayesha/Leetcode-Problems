class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int ans;
        int n=weights.size();
        int lowCap=*max_element(weights.begin(),weights.end());
        int highCap=accumulate(weights.begin(),weights.end(),0);
        while(lowCap<=highCap){
            int midCap=(lowCap+highCap)/2;
            int i=0,days_needed=1,sum_weights=0;
            while(i<n){
                sum_weights+=weights[i];
                if(sum_weights>midCap){
                    ++days_needed;
                    sum_weights= weights[i];             
                }
                i++;
            }
            if( days_needed <= days){
                ans= midCap;
                highCap=midCap-1;
            }
            else{
                lowCap=midCap+1;
            }
        }
        return ans;
    }
};