// https://leetcode.com/problems/string-matching-in-an-array/?envType=daily-question&envId=2025-01-07

class Solution
{
public:
    vector<string> stringMatching(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &x, const string &y)
             { return x.size() < y.size(); });
        vector<string> ans;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if (words[j].find(words[i]) != string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};