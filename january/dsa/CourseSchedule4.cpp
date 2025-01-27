class Solution
{
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        // Do the topological sort

        vector<vector<bool>> o(n, vector<bool>(n)), temp(n, vector<bool>(n));
        for (const auto v : prerequisites)
        {
            o[v[0]][v[1]] = 1;
        }

        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i == k || j == k)
                        continue;
                    if (o[i][j] == 1)
                        continue;
                    if (o[i][k] != 0 && o[k][j] != 0)
                        temp[i][j] = 1;
                }
            }

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (temp[i][j] == 1)
                        o[i][j] = temp[i][j];
                }
            }
        }

        // for (int i = 0; i < n; ++i) {
        //     for(int j = 0; j < n; ++j) {
        //         cout<<o[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<bool> ans;
        for (const auto &v : queries)
        {
            ans.push_back(o[v[0]][v[1]]);
        }

        return ans;
    }
};