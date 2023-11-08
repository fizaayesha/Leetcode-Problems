//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        /* Method:-01
        sort(a,a+n);
        */
        /* Method:-02
        int countZ=0,countO=0,countT=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)countZ++;
            if(a[i]==1)countO++;
            if(a[i]==2)countT++;
        }
        int i=0;
        while(countZ--){
            a[i++]=0;
        }
        while(countO--){
            a[i++]=1;
        }
        while(countT--){
            a[i++]=2;
        }
        */
        /* Method:-03*/
        int start=0, end=n-1,mid=0;
        while(mid<=end){
            if(a[mid]==0){
                swap(a[mid],a[start]);
                start++;
                mid++;
            }
            else if(a[mid]==1){
                mid++;
            }
            else if(a[mid]==2){
                swap(a[mid],a[end]);
                end--;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends