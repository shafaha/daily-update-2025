// https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13

class Solution
{
public:
    int minimumLength(string s)
    {
        vector<int> vec(26);
        for (char c : s)
        {
            ++vec[c - 'a'];
        }

        int total = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (vec[i] % 2)
                total += 1;
            else if (vec[i] >= 2)
                total += 2;
        }

        return total;
    }
};