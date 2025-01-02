class Solution {
public:
    bool isPSu(string &s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solveBT(string &s, int n, int ind, int &count){
        // if(ind==n){
        //     return;
        // }
        for(int i=ind;i<n;i++){
            if(isPSu(s,ind,i)){
                count++;
            }
            // solveBT(s,n,i+1,count);
        }
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.length();i++)
            solveBT(s,s.length(),i,count);
        return count;
    }
};