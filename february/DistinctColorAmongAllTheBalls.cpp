// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/?envType=daily-question&envId=2025-02-07
class Solution
{

public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        static auto init = []()
        {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            return nullptr;
        }();
        unordered_map<int, int> mp;
        unordered_map<int, int> state;
        // state.reserve(;
        vector<int> ans;
        int cnt = 0;
        for (const auto &v : queries)
        {
            if (!state[v[0]])
            {
                mp[v[1]]++;
                state[v[0]] = v[1];
                if (mp[v[1]] == 1)
                    ++cnt;
            }
            else
            {
                int x = state[v[0]];
                mp[x]--;
                if (mp[x] == 0)
                    --cnt;
                mp[v[1]]++;
                state[v[0]] = v[1];
                if (mp[v[1]] == 1)
                    ++cnt;
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};