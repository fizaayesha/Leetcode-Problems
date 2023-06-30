class Solution {
public:
    int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1); // Dummy index to handle empty stack case
    int maxLen = 0;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else { // s[i] == ')'
            st.pop();
            if (st.empty()) {
                st.push(i); // Push the current index as a potential starting point
            } else {
                maxLen = max(maxLen, i - st.top()); // Update the maximum length
            }
        }
    }

    return maxLen;
}
};