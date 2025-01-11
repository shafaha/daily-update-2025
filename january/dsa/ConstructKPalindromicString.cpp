// https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        if (k == 0)
            return true;
        if (k > s.size())
            return false;
        // using character of the s can we construst the palindromic string
        vector<int> vec(26);
        for (char c : s)
        {
            vec[c - 'a'] += 1;
        }

        int total = 0;
        for (int i = 0; i < 26; ++i)
        {
            total += vec[i] % 2;
        }

        return total <= k;
    }
};