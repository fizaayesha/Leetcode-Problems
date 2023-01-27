class Solution {
public: bool concat_possible(string &word,vector<string>& words, unordered_map<string,int>&mp){
          int size=word.size();
          for(int i=1;i<size;++i){ 
              string prefix=word.substr(0,i);// left subpart
              string suffix=word.substr(i);  // right subpart
              if(mp[prefix] && (mp[suffix] || concat_possible(suffix,words,mp))){   /*checking if left and right subpart is present in map or not .
if one subpart is present(lets say prefix) and other is not(lets say suffix) then recursively check the suffix subpart .if both subparts is present then return true*/
                  return true;
              }
          }
          return false;
}
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        unordered_map<string,int>mp; 
        for(auto string:words){   //storing each words into unordered_map
            mp[string]++;
        }


        for(auto &word:words){  //check for each word .if its return true then add it into our solution
            if(concat_possible(word,words,mp)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};
