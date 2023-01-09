class Solution
{
public:
    bool isItPossible(string word1, string word2)
    {
        unordered_map<char,int> mp1,mp2;
        for(auto it:word1){
            mp1[it]++;
        }
        for(auto it:word2){
            mp2[it]++;
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                int ch1=i+'a',ch2=j+'a';
                if(mp1.count(ch1) && mp2.count(ch2)){
                    if(--mp1[ch1]==0){
                        mp1.erase(ch1);
                    }
                    if(--mp2[ch2]==0){
                        mp2.erase(ch2);
                    }
                    mp1[ch2]++;
                    mp2[ch1]++;
                    if(mp1.size()==mp2.size()){
                        return true;
                    }
                    if(--mp1[ch2]==0){
                        mp1.erase(ch2);
                    }
                    if(--mp2[ch1]==0){
                        mp2.erase(ch1);
                    }
                    mp1[ch1]++;
                    mp2[ch2]++;
                }
            }
        }
        return false;
    }
};