// 2270. Number of Ways to Split Array
// https://leetcode.com/problems/number-of-ways-to-split-array/description/?envType=daily-question&envId=2025-01-03

class Solution
{
public:
    int waysToSplitArray(vector<int> &t)
    {
        long long sm = 0;
        for (int i = 1; i < t.size(); ++i)
        {
            sm += t[i];
        }

        long long tm = t[0];
        int total = 0;
        for (int i = 1; i < t.size(); ++i)
        {
            if (tm >= sm)
                ++total;
            tm += t[i];
            sm -= t[i];
        }

        return total;
    }
};