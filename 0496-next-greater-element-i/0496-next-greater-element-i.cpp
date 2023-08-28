class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        stack<int> st;
        unordered_map<int,int>mp;
        vector<int> ans;
        st.push(-1);
        int j=0;
        for(int i=n2-1;i>=0;i--){
            int curr=nums2[i];
            while(!st.empty() && st.top()<=curr){
                st.pop();
            }
            int res;
            if(st.empty()){
                res=-1;
            }
            else{
                res=st.top();
            }
            mp.insert({nums2[i],res});
            st.push(nums2[i]);
        }
        for(auto i:nums1){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};