class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro=1,sum=0;
        int count=-1;
        while(n!=0){
            count++;
            int rem=n%10;
            n/=10;
            sum+=rem;
            pro*=rem;
        }
        return pro-sum;
    }
};