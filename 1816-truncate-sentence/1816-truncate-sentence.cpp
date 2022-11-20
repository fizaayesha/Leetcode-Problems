class Solution {
public:
    string truncateSentence(string s, int k) {
        int n=s.length();
        string ans="";
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                count++;
                if(count==k){
                    break;
                }
            }
            ans+=s[i];
        }
        return ans;
    }
};