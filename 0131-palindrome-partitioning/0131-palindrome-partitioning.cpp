class Solution
{
public:
    bool isPalindrome(int start, int end, string s)
    {
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void palindromicPartition(int index, vector<string> &ds, vector<vector<string>> &ans, string &str){
        if(index==str.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<str.length();i++){
            if(isPalindrome(index,i,str)){
                ds.push_back(str.substr(index,i-index+1));
                palindromicPartition(i+1,ds,ans,str);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> ds;
        palindromicPartition(0,ds,ans,s);
        return ans;
    }
};