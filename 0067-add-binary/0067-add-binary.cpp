class Solution {
public:
    // int bin_dec(int n){
    //     int sum = 0;
    //     int count = -1;
    //     while (n != 0)
    //     {
    //         count++;
    //         int rem = n % 10;
    //         n = n / 10;
    //         int res = rem * pow(2, count);
    //         sum += res;
    //     }
    //     return sum;
    // }
    // int dec_bin(int n){
    //     int sum = 0;
    //     int count = -1;
    //     while (n != 0)
    //     {
    //         count++;
    //         int rem = n % 2;
    //         n = n / 2;
    //         int res = rem * pow(10, count);
    //         sum += res;
    //     }
    //     return sum;
    // }
    // string addBinary(string a, string b) {
    //     int a1=stoi(a);
    //     int a2=bin_dec(a1);
    //     int b1=stoi(b);
    //     int b2=bin_dec(b1);
    //     int c=a2+b2;
    //     int c1=dec_bin(c);
    //     return to_string(c1);
    // }
    string addBinary(string a, string b) {
        int n1=a.length()-1,n2=b.length()-1; 
        string ans;
        int carry=0;
        while(n1>=0 || n2>=0 || carry){
            if(n1>=0){
                carry+=a[n1]-'0';
                n1--;
            }
            if(n2>=0){
                carry+=b[n2]-'0';
                n2--;
            }
            ans+=(carry%2+'0');
            carry/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

};