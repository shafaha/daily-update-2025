// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/?envType=daily-question&envId=2025-01-12
// 2116. Check if a Parentheses String Can Be Valid

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        if (s.size() % 2)
            return false;
        int closing = 0, opening = 0, l = 0, r = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (locked[i] == '0')
                ++l;
            else if (s[i] == '(')
                ++opening;
            else
                ++closing;

            if (closing - opening > l)
                return false;
        }

        opening = 0;
        closing = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (locked[i] == '0')
                ++r;
            else if (s[i] == '(')
                ++opening;
            else
                ++closing;

            if (opening - closing > r)
                return false;
        }

        return true;
    }
};