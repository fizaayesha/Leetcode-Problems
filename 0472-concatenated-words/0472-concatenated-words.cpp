class Solution {
public:
    bool concatenate_check(string &word, vector<string> &words,unordered_map<string,int> &mp){
        int n=word.length();
        for(int i=1;i<n;++i){
            string prefix=word.substr(0,i);
            string suffix=word.substr(i);
            if(mp[prefix] && (mp[suffix] || concatenate_check(suffix,words,mp))){
                return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(auto str: words){
            mp[str]++;
        }
        for(auto &word: words){
            if(concatenate_check(word,words,mp)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};