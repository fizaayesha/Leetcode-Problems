class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; i++) {
        projects[i] = {capital[i], profits[i]};
    }
    sort(projects.begin(), projects.end()); // sort projects by capital
    priority_queue<int> available; // store profits sorted (highest value)
    int i = 0;
    while (k > 0) {
        while (i < n && projects[i].first <= w) {
            available.push(projects[i].second);
            i++;
        }
        if (available.empty()) break;
        w += available.top();
        available.pop();
        k--;
    }
    return w;
    }
};