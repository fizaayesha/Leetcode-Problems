class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        vector<int> ans;
        for (int i = 0; i < n1; i++)
        {
            ans.push_back(nums1[i]);
        }
        for (int i = 0; i < n2; i++)
        {
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(), ans.end());
        // int n = ans.size();
        double fin;
        if (n % 2 == 0)
        {
            fin = (ans[(n / 2) - 1] + ans[n / 2]) / 2.0;
        }
        else
        {
            fin = ans[(n - 1) / 2];
        }
        return fin;
    }
};