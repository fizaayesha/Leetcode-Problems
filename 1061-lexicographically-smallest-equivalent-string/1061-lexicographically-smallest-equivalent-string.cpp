class Solution {
public:
    vector<int> headChar;
    int findParent(int x){
        if(headChar[x]==-1){
            return x;
        }
        return headChar[x]=findParent(headChar[x]);
    }
    void unionFunc(int x, int y){
        int parentx=findParent(x);
        int parenty=findParent(y);
        if(parentx==parenty){
            return;
        }
        headChar[max(parentx,parenty)]=min(parentx,parenty);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        headChar.resize(26,-1);
        for(int i=0;i<s1.size();i++){
            unionFunc(s1[i]-'a',s2[i]-'a');
        }
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=findParent(baseStr[i]-'a')+'a';
        }
        return baseStr;
    }
};