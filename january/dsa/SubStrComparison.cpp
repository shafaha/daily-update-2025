// 3042. Count Prefix and Suffix Pairs I
// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=daily-question&envId=2025-01-08

class Solution
{
public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int total = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if (words[i].size() > words[j].size())
                    continue;
                int x = words[i].size();
                int y = words[j].size();
                // cout<<words[i]<<" "<<words[j].substr(y-x, x)<<endl;
                if (words[j].substr(0, x) == words[i] && words[j].substr(y - x, x) == words[i])
                    ++total;
            }
        }

        return total;
    }
};