//  https://leetcode.com/problems/redundant-connection/description/?envType=daily-question&envId=2025-01-29

class Solution
{
public:
    int findRep(vector<int> &vec1, int v)
    {
        if (vec1[v] == v)
            return v;

        int y = findRep(vec1, vec1[v]);
        vec1[v] = y;

        return y;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> v(n + 1);
        for (int i = 1; i < n + 1; ++i)
        {
            v[i] = i;
        }

        for (vector<int> &e : edges)
        {
            // sort(e.begin(), e.end());
            int x = findRep(v, e[0]);
            int y = findRep(v, e[1]);
            int z = min(x, y);
            // cout<<x<<" "<<y<<endl;

            if (x == y)
                return e;

            v[v[x]] = z;
            v[v[y]] = z;
            v[e[0]] = z;
            v[e[1]] = z;
        }

        return {};
    }
};