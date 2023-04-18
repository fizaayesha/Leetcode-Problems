class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0,j=0;
        int n1=word1.length(),n2=word2.length();
        while(n1!=0 && n2!=0){
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
            n1--;
            n2--;
        }
        while(n1!=0){
            ans.push_back(word1[i]);
            i++;
            n1--;
        }
        while(n2!=0){
            ans.push_back(word2[j]);
            j++;
            n2--;
        }
        return ans;
    }
};