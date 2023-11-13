class Solution {
public:
    int isVowel(char ch)
    {
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);
    }
    string sortVowels(string s) {
        int n=s.length();
        string conso="",vowel="";
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                vowel+=s[i];
            }
            else{
                conso+=s[i];
            }
        }
        sort(vowel.begin(),vowel.end());
        string ans="";
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                ans+=vowel[j];
                j++;
            }
            else{
                ans+=conso[k];
                k++;
            }
        }
        return ans;
    }
};