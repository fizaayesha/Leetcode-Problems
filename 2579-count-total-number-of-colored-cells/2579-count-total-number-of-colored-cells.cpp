class Solution
{
public:
    long long coloredCells(int n)
    {
       long long ans = n;

        return ans * ans + ((ans - 1) * (ans - 1));
    }
};
