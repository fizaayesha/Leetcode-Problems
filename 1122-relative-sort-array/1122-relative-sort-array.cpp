class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> m;
        vector<int> ans;
        for(auto it : arr1)
        {
            m[it]++;
        }
        for(auto it :arr2)
        {
            while(m[it]--)
            {
                ans.push_back(it);
            }
            m.erase(it);
        }
        for(auto i : m)
        {
            while(i.second--)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};