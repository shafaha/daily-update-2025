// 6. Zigzag Conversion
// https://leetcode.com/problems/zigzag-conversion/description/

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int x = numRows - 1;
        int difference = 2 * x, second = 2 * x;
        string ans;
        for (int i = 0; i < numRows; ++i)
        {
            int j = i;
            for (; j < s.size(); j += difference)
            {
                ans.push_back(s[j]);
                if (i == 0 || i == x)
                    continue;
                if (j + second < s.size())
                    ans.push_back(s[j + second]);
            }
            second -= 2;
        }

        return ans;
    }
};