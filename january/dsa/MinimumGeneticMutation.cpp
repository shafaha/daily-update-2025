// https://leetcode.com/problems/minimum-genetic-mutation/?envType=problem-list-v2&envId=hash-table
// 433. Minimum Genetic Mutation

class Solution
{
public:
    int diffCount(const string &a, const string &b)
    {
        int cnt = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            cnt += a[i] != b[i];
        }

        return cnt;
    }

    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        // Graph type thing lag raha hai meko
        unordered_map<int, vector<int>> mp;
        int start = -1;
        int dest = -1;

        for (int i = 0; i < bank.size(); ++i)
        {
            if (endGene == bank[i])
                dest = i;
            if (diffCount(startGene, bank[i]) == 1)
            {
                mp[start].push_back(i);
                mp[i].push_back(start);
            }
        }
        if (dest == -1)
            return -1;

        unordered_map<int, int> isTraversed;
        unordered_map<int, int> distance;
        distance[start] = 0;
        isTraversed[start] = 1;
        queue<int> q;
        q.push(start);

        for (int i = 0; i < bank.size(); ++i)
        {
            isTraversed[i] = 0;
            distance[i] = -1;
            for (int j = i + 1; j < bank.size(); ++j)
            {
                if (diffCount(bank[i], bank[j]) == 1)
                {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            int dis = distance[x];
            for (int i : mp[x])
            {
                if (isTraversed[i] == 0)
                {
                    distance[i] = dis + 1;
                    q.push(i);
                    isTraversed[i] = 1;
                }
            }
        }

        return distance[dest];
    }
};