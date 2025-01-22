//  https://leetcode.com/problems/map-of-highest-peak/submissions/1517142612/?envType=daily-question&envId=2025-01-22

class Solution
{
public:
    struct Node
    {
        int x, y, val;
        friend bool operator<(const Node &a, const Node &b)
        {
            return a.val > b.val;
        }
    };
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        queue<Node> pq;
        int r = isWater.size(), c = isWater[0].size();
        vector<vector<int>> vec = {{0, 0, 1, -1}, {1, -1, 0, 0}};
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                if (isWater[i][j] == 1)
                {
                    pq.push({i, j, 0});
                    isWater[i][j] = 0;
                }
                else
                {
                    isWater[i][j] = -1;
                }
            }
        }

        if (pq.size() == 0)
        {
            pq.push({0, 0, 0});
        }

        Node temp;
        while (!pq.empty())
        {
            temp = pq.front();
            pq.pop();
            for (int i = 0; i < 4; ++i)
            {
                int x = temp.x + vec[0][i];
                int y = temp.y + vec[1][i];
                if (x >= 0 && x < r && y >= 0 && y < c && isWater[x][y] == -1)
                {
                    isWater[x][y] = temp.val + 1;
                    pq.push({x, y, temp.val + 1});
                }
            }
        }

        return isWater;
    }
};