// 1930. Unique Length-3 Palindromic Subsequences
// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        vector<int> vec(26), tec(26);
        vector<bool> isPresent(26 * 26);
        for (char c : s)
        {
            ++vec[c - 'a'];
        }

        tec[s[0] - 'a'] += 1;
        vec[s[0] - 'a'] -= 1;
        int total = 0;
        for (int i = 1; i < s.size() - 1; ++i)
        {
            int y = s[i] - 'a';
            vec[y] -= 1;
            for (int j = 0; j < 26; ++j)
            {
                if (tec[j] > 0 && vec[j] > 0)
                {
                    int z = j * 26 + y;
                    // cout<<z<<endl;
                    total += !isPresent[z];
                    isPresent[z] = true;
                }
            }
            tec[y] += 1;
        }

        return total;
    }
};