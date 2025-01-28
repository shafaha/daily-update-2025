// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/?envType=daily-question&envId=2025-01-28

class Solution
{
public:
    struct Node
    {
        int x, y;
    };

    int findMaxFish(vector<vector<int>> &grid)
    {
        int total = 0;
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> vec = {
            {0, 0, 1, -1},
            {1, -1, 0, 0}};
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (grid[i][j] == 0)
                    continue;

                queue<Node> q;
                q.push({i, j});
                Node temp;

                int t = grid[i][j];
                grid[i][j] = 0;
                // cout<<i<<" "<<j<<" | ";
                while (!q.empty())
                {
                    temp = q.front();
                    q.pop();

                    for (int l = 0; l < 4; ++l)
                    {
                        int x = temp.x + vec[0][l];
                        int y = temp.y + vec[1][l];
                        if (x < r && x >= 0 && y < c && y >= 0 && grid[x][y] != 0)
                        {
                            // cout<<x<<" "<<y<<" | ";
                            q.push({x, y});
                            t += grid[x][y];
                            grid[x][y] = 0;
                        }
                    }
                }

                // cout<<total<<endl;
                total = max(total, t);
            }
        }

        return total;
    }
};