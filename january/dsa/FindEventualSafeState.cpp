// https://leetcode.com/problems/find-eventual-safe-states/description/?envType=daily-question&envId=2025-01-24

class Solution
{
public:
    void doit(int v, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &iTR)
    {
        if (visited[v])
            return;
        visited[v] = true;

        if (graph[v].size() == 0)
        {
            iTR[v] = true;
            return;
        }

        for (int i : graph[v])
        {
            doit(i, graph, visited, iTR);
        }

        bool flag = true;
        for (int i : graph[v])
        {
            if (!iTR[i])
            {
                flag = false;
                break;
            }
        }

        iTR[v] = flag;
        return;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int nodes = graph.size();
        vector<bool> visited(nodes);
        vector<bool> iTR(nodes);
        for (int i = 0; i < nodes; ++i)
        {
            if (!visited[i])
            {
                doit(i, graph, visited, iTR);
            }
        }

        vector<int> ans;
        for (int i = 0; i < nodes; ++i)
        {
            if (iTR[i])
                ans.push_back(i);
        }

        return ans;
    }
};