//  https://leetcode.com/problems/count-servers-that-communicate/?envType=daily-question&envId=2025-01-23

class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        vector<int> vec(c), tec(r);
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                tec[i] += grid[i][j];
                vec[j] += grid[i][j];
            }
        }

        int total = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                total += (tec[i] > 1 || vec[j] > 1) && grid[i][j] ? 1 : 0;
            }
        }

        return total;
    }
};