class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int a[128]={0}, b[128]={0};
        for(int i=0;i<s.length();i++){
            if(a[s[i]]!=b[t[i]]){
                return false;
            }
            a[s[i]]=i+1;
            b[t[i]]=i+1;
        }
        return true;
    }
};