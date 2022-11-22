class Solution {
public:
    int lengthOfinteger(int n)
    {
        int length = 0;
        while (n != 0)
        {
            int rem = n % 10;
            n /= 10;
            length++;
        }
        return length;
    }
    int reverse(int x)
    {
        long long sum = 0;
        int length = lengthOfinteger(x)-1;
        while (x != 0)
        {
            int rem = x % 10;
            x /= 10;
            long long ans = rem * pow(10, length);
            sum += ans;
            length--;
        }
        return sum;
    }
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        if(x==reverse(x)){
            return true;
        }
        return false;
    }
};