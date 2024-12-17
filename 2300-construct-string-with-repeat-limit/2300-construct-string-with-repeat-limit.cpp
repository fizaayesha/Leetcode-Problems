class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        priority_queue<pair<char,int>> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push({'a'+i,freq[i]});
            }
        }
        string result;
        while(!pq.empty()){
            char key_ch=pq.top().first;
            int value_count=pq.top().second;
            pq.pop();
            int mini=min(repeatLimit,value_count);
            result.append(mini,key_ch);
            value_count-=mini;
            if(value_count>0){
                if(pq.empty()){
                    break;
                }
                char key_nextCh=pq.top().first;
                int value_nextCount=pq.top().second;
                pq.pop();
                result+=key_nextCh;
                value_nextCount--;
                if(value_nextCount>0){
                    pq.push({key_nextCh,value_nextCount});
                }
                pq.push({key_ch,value_count});
            }
        }
        return result;
    }
};