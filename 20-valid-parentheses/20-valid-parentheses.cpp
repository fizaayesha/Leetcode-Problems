class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        int n=s.length();
        if(n==0){
            return 1;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{' ){
                st.push(s[i]);
            }
            else if(!st.empty()){
                if(
                (s[i]==')' && st.top()=='(')
                ||
                (s[i]==']' && st.top()=='[')
                ||
                (s[i]=='}' && st.top()=='{')
                   ){
                st.pop();
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        if(st.empty()){
            return 1;
        }
        else{
            return 0;
        }
    }
};