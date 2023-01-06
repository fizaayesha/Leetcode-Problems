class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &p)
    {
        sort(p.begin(), p.end());
        int lpoint = p[0][1];
        int count = 1;
        for (auto points : p)
        {
            if (points[0] > lpoint)
            {
                count++;
                lpoint = points[1];
            }
            lpoint = min(points[1], lpoint);
        }
        return count;
    }
};
