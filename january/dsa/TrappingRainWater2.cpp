// https://leetcode.com/problems/trapping-rain-water-ii/?envType=daily-question&envId=2025-01-19

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

    int trapRainWater(vector<vector<int>> &h)
    {
        int r = h.size(), c = h[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c));
        priority_queue<Node> pq;
        for (int i = 0; i < c; ++i)
        {
            pq.push({0, i, h[0][i]});
            visited[0][i] = true;
            pq.push({r - 1, i, h[r - 1][i]});
            visited[r - 1][i] = true;
        }

        for (int i = 1; i < r - 1; ++i)
        {
            pq.push({i, 0, h[i][0]});
            visited[i][0] = true;
            pq.push({i, c - 1, h[i][c - 1]});
            visited[i][c - 1] = true;
        }

        Node temp;
        int total = 0;
        int mx = 0;
        while (!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            int x = temp.x;
            int y = temp.y;
            int val = temp.val;

            mx = max(mx, temp.val);
            // cout<<x<<" "<<y<<" "<<temp.val<<" "<<mx<<endl;
            if (mx > h[x][y])
            {
                total += mx - h[x][y];
            }

            // if (visited[x][y])  continue;

            if (x + 1 < r - 1 && !visited[x + 1][y])
            {
                pq.push({x + 1, y, h[x + 1][y]});
                visited[x + 1][y] = true;
            }

            if (x - 1 >= 0 && !visited[x - 1][y])
            {
                pq.push({x - 1, y, h[x - 1][y]});
                visited[x - 1][y] = true;
            }

            if (y + 1 < c - 1 && !visited[x][y + 1])
            {
                pq.push({x, y + 1, h[x][y + 1]});
                visited[x][y + 1] = true;
            }

            if (y - 1 >= 0 && !visited[x][y - 1])
            {
                pq.push({x, y - 1, h[x][y - 1]});
                visited[x][y - 1] = true;
            }
        }

        return total;
    }
};