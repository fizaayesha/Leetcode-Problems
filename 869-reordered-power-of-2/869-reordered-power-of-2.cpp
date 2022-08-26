class Solution {
public:
    string sortStr(int n){
        string t=to_string(n);
        sort(t.begin(),t.end());
        return t;
    }
    bool reorderedPowerOf2(int n) {
        string s=sortStr(n);
        for(int i=0;i<30;i++){
            string t=sortStr(1<<i);
            if(s==t){
                return true;
            }
        }
        return false;
    }
};