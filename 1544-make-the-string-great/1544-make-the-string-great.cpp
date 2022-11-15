class Solution {
public:
    string makeGood(string s) {
     int n = s.size();
        stack<char> st;
        string ans = "";
        int i = 0;
        while (i != n)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if (islower(st.top()))
                {
                    if (s[i] == (char)toupper(st.top()))
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
                else if (isupper(st.top()))
                {
                    if (s[i] == (char)tolower(st.top()))
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
            }
            i++;
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
                reverse(ans.begin(), ans.end());
        return ans;
    }
};