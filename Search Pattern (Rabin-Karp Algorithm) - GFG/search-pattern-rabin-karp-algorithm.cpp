//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            vector<int> ans;
            int n1=txt.length();
            int n2=pat.length();
            int prime=31,mod=1e9+9;
            vector<long long> p_pow(n1);
            p_pow[0]=1;
            for(int i=1;i<n1;i++){
                p_pow[i]=(p_pow[i-1]*prime)%mod;
            }
            vector<long long> h(n1+1,0);
            for(int i=0;i<n1;i++){
                h[i+1]=(h[i]+(txt[i]-'a'+1)*p_pow[i])%mod;
            }
            long long hash=0;
            for(int i=0;i<n2;i++){
                hash=(hash+(pat[i]-'a'+1)*p_pow[i])%mod;
            }
            for(int i=0;i+n2-1<n1;i++){
                long long hash_p=(h[i+n2]+mod-h[i])%mod;
                if(hash_p==(hash*p_pow[i])%mod){
                    ans.push_back(i+1);
                }
            }
            vector<int> ans1(1,-1);
            if(ans.size()==0){
                return ans1;
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends