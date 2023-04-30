class Solution {
public:
int dfs(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
        return 0; // Base case: out of bounds or land cell
    }
    int fishCaught = grid[r][c]; // Catch fish at current cell
    grid[r][c] = 0; // Mark cell as caught
    int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Possible movements
    for (int i = 0; i < 4; i++) {
        int newR = r + moves[i][0];
        int newC = c + moves[i][1];
        fishCaught += dfs(grid, newR, newC); // Recursively search adjacent cells
    }
    return fishCaught;
}

int findMaxFish(vector<vector<int>>& grid) {
    int maxFish = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] > 0) { // Start DFS search from water cell
                int fishCaught = dfs(grid, i, j);
                maxFish = max(maxFish, fishCaught);
            }
        }
    }
    return maxFish;
}};