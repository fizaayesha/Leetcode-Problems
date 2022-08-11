class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t sum=0;
        for(int i=31;i>=0;i--){
            int rem=n%2;
            if(rem==1){
                sum+=pow(2,i);
            }
            n/=2;
        }
        return sum;
    }
};