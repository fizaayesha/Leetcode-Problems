class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        for(int i=0;i<n;i++){
            string s1="";
            for(int j=i;j<n;j++){
                s1+=haystack[j];
                if(s1==needle){
                    return i;
                }
            }
        }
        return -1;
    }
};