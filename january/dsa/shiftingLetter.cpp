// 2381. Shifting Letters II
// https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        if (s.size() == 0)
            return s;
        vector<int> vec(s.size() + 1);
        for (auto &v : shifts)
        {
            if (v[2] == 1)
            {
                vec[v[0]] += 1;
                vec[v[1] + 1] -= 1;
            }
            else
            {
                vec[v[0]] -= 1;
                vec[v[1] + 1] += 1;
            }
        }

        for (int i = 1; i < vec.size(); ++i)
        {
            vec[i] += vec[i - 1];
        }

        for (int i = 0; i < vec.size() - 1; ++i)
        {
            // cout<<vec[i]<<" ";
            vec[i] += (s[i] - 'a');
            vec[i] %= 26;
            if (vec[i] < 0)
                vec[i] += 26;
            s[i] = 'a' + vec[i];
        }

        return s;
    }
};
