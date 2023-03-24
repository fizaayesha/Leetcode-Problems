//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        unordered_map<int,int> m;
        int n=S.size();
        for(int i=0;i<n;i++){
            m[S[i]]++;
        }
        string ans1="",ans2="";
        int i=0,e=n-1;
        int f=1;
        int cnt=0;
        while(i<=e){
            if(f==1){
                if(m[S[i]]>1){
                    m[S[i]]--;
                    f=0;
                    i++;
                    cnt++;
                }
                else if(m[S[i]]==1){
                    ans1+=S[i];
                    i++;
                }
            }
            else{
                if(m[S[e]]>1){
                    m[S[e]]--;
                    f=1;
                    e--;
                    cnt--;
                }
                else if(m[S[e]]==1){
                    ans2+=S[e];
                    e--;
                }
            }
        }
        reverse(ans2.begin(),ans2.end());
        string ans=ans1+ans2;
        if(cnt%2!=0){
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends