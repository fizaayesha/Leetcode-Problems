// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack <int> s;
    int c=0;
    while(c!=k){
        int e=q.front();
        s.push(e);
        q.pop();
        c++;
    }
    while(!s.empty()){
        int e=s.top();
        q.push(e);
        s.pop();
    }
    int sz=q.size()-k;
    while(sz--){
        int e=q.front();
        q.push(e);
        q.pop();
    }
    return q;
}