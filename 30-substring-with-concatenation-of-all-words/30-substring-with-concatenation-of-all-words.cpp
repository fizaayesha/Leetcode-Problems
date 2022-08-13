class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector <int> ans;
        unordered_map <string, int> m;
        for(auto w:words){
            m[w]++;
        }
        int s_len=s.length();
        int word_len=words[0].length();
        int words_size=words.size();
        int sub_len=(word_len*words_size);
        unordered_map <string,int> m1;
        unordered_map <string,int> m_sub;
        for(int i=0;i<s_len-sub_len+1;i++){
            m_sub.clear();
            m1=m;
            for(int j=i;j<(i+sub_len);j+=word_len){
                string subStr=s.substr(j,word_len);
                m_sub[subStr]++;
                if(m_sub[subStr]>m1[subStr]){
                    break;
                }
            }
            if(m==m_sub){
                ans.push_back(i);
            }
        }
        return ans;
    }
};