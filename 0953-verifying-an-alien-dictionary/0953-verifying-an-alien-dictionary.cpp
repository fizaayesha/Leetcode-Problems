class Solution {
public:
    bool compare(string a,string b, string order){
        int i=0;
        while(i<a.length() && a[i]==b[i]){
            i++;
        }
        if(a.length()==i){
            return true;
        }
        if(b.length()==i){
            return false;
        }
        return (order.find(a[i])<order.find(b[i]));
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<words.size()-1;i++){
            if(!compare(words[i],words[i+1],order)){
                return false;
            }
        }
        return true;
    }
};