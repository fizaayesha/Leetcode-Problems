class Solution {
private:
    int RED_COLOR = 0;
    int BLUE_COLOR = 1;
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> g(n); 
        for (auto edge : redEdges)
        {
            g[edge[0]].push_back({edge[1], RED_COLOR});
        }

        for (auto edge : blueEdges)
        {
            g[edge[0]].push_back({edge[1], BLUE_COLOR});
        }

        queue<pair<int, int>> q;
        q.push({0, RED_COLOR});  
        q.push({0, BLUE_COLOR});

        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        dist[0][RED_COLOR] = 0;
        dist[0][BLUE_COLOR] = 0;

        while (!q.empty())
        {
            int node = q.front().first;
            int color = q.front().second;
            q.pop();

            for (auto nbr : g[node])
            {
                int nbr_node = nbr.first, nbr_color = nbr.second;
                if (dist[nbr_node][nbr_color] == INT_MAX && color != nbr_color)
                {
                    dist[nbr_node][nbr_color] = dist[node][color] + 1;
                    q.push(nbr);
                }
            }
        }

        vector<int> result(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (dist[i][RED_COLOR] != INT_MAX || dist[i][BLUE_COLOR] != INT_MAX)
            {
                result[i] = min(dist[i][RED_COLOR], dist[i][BLUE_COLOR]);
            }
        }

        return result;        
    }
};