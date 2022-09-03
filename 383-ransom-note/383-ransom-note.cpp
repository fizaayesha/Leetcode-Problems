class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int count[26]={0};
        for(char ch:magazine){
            count[ch-'a']++;
        }
        for(char ch: ransomNote){
            if(count[ch-'a']--<=0){
                return false;
            }
        }
        return true;
    }
};