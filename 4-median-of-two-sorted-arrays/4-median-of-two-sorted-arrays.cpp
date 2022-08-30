class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        int n1=nums1.size();
        int n2=nums2.size();
        int i=0,j=0;
        for(int i=0;i<n1;i++){
            ans.push_back(nums1[i]);
        }
        for(int i=0;i<n2;i++){
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(),ans.end());
        double fin;
        if((n1+n2)%2==0){
            fin =(ans[(n1+n2)/2] + ans[(n1+n2)/2-1])/2.0;
        }
        else{
            fin=ans[(n1+n2-1)/2];
        }
        return fin;
    }
};