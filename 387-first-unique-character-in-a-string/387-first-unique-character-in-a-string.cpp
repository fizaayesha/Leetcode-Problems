class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(i!=j && s[i]==s[j]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                return i;
            }
        }
        return -1;
    }
};