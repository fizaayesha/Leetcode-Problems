class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        int count1=0,count2=0;
        int start=0,end=n-1;
        while(start<=end){
            if(s[start]=='a' || s[start]=='e' || s[start]=='i' || s[start]=='o' || s[start]=='u' ||
              s[start]=='A' || s[start]=='E' || s[start]=='I' || s[start]=='O' || s[start]=='U'
              ){
                count1++;
            }
            if(s[end]=='a' || s[end]=='e' || s[end]=='i' || s[end]=='o' || s[end]=='u' ||
              s[end]=='A' || s[end]=='E' || s[end]=='I' || s[end]=='O' || s[end]=='U'
              ){
                count2++;
            }  
            start++;
            end--;
        }
        if(count1==count2){
            return true;
        }
        return false;
    }
};