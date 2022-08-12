class Solution {
public:
    string reverseVowels(string s) {
        string test="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                test+=s[i];
                s[i]='~';
            }
        }
        int newN=test.length()-1;
        for(int i=0;i<n;i++){
            if(s[i]=='~'){
                s[i]=test[newN];
                newN--;
            }
        }
        return s;
    }
};