//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    //Your code here
    int n=s.length();
    int p=31;
    int mod=1e9+9;
    vector<long long>power_p(n);
    power_p[0]=1;
    for(int i=1;i<n;i++){
        power_p[i]=(power_p[i-1]*p)%mod;
    }
    vector<long long>h(n+1,0);
    for(int i=0;i<n;i++){
        h[i+1]=(h[i]+(s[i]-'a'+1)*power_p[i])%mod;
    }
    int cnt = 1;
    for (int l = 1; l <= n; l++)
    {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++)
        {
            long long cur_h = (h[i + l] + mod - h[i]) % mod;
            cur_h = (cur_h * power_p[n - i - 1]) % mod;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}