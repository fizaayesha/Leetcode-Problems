class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n=A.size();      
        vector<int> ans(n,0);
        vector<int>test(n+1,0);
        int count=0;
        for(int i=0;i<n;i++){
            test[A[i]]++;
            if(test[A[i]]==2){
                count++;
            }
            test[B[i]]++;
            if(test[B[i]]==2){
                count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};