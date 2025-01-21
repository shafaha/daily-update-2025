// https://leetcode.com/problems/grid-game/?envType=daily-question&envId=2025-01-21

class Solution
{
public:
    long long gridGame(vector<vector<int>> &grid)
    {
        int c = grid[0].size();
        long long l = 0, r = 0;
        for (int i = c - 1; i > 0; --i)
            r += grid[0][i];
        long long val = r;
        for (int i = 1; i < c; ++i)
        {
            l += grid[1][i - 1];
            r -= grid[0][i];
            if (val > max(l, r))
            {
                val = max(l, r);
            }
        }

        return val;
    }
};