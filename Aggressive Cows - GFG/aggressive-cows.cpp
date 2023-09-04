//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    bool isPossible(int n, int k, int mid, vector<int> & stalls){
        int cowCount=1;
        int lastPos=stalls[0];
        for(int i=0;i<n;i++){
            if(stalls[i]-lastPos>=mid){
                cowCount++;
                if(cowCount==k){
                    return true;
                }
                lastPos=stalls[i];
            }
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int ans=-1;
        int start=0, end=*max_element(stalls.begin(),stalls.end());
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(n,k,mid, stalls)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends