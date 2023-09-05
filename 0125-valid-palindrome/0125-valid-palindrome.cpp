class Solution {
public:
    bool palindrome(string s){
        int n=s.length();
        int start=0,end=n-1;
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    string toLowerCaseString(string s){
        int n=s.length();
        for(int i=0;i<n;i++){
           s[i]=tolower(s[i]);
        }
        return s;
    }
    bool isPalindrome(string s) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9'){
                ans.push_back(s[i]);
            }
        }
        if(ans.length()==0){
            return true;
        }
        // cout<<ans<<endl;
        ans=toLowerCaseString(ans);
        // cout<<ans<<endl;
        return palindrome(ans);
    }
};