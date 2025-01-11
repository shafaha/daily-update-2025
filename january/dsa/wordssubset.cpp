// https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10
// 916. Word Subsets

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<int> vec(26);
        vector<int> temp(26);
        for (int i = 0; i < words2.size(); ++i)
        {
            for (char c : words2[i])
            {
                ++temp[c - 'a'];
            }

            for (int j = 0; j < 26; ++j)
            {
                if (temp[j] > vec[j])
                {
                    vec[j] = temp[j];
                }

                temp[j] = 0;
            }
        }

        vector<string> ans;
        for (int i = 0; i < words1.size(); ++i)
        {
            for (char c : words1[i])
            {
                ++temp[c - 'a'];
            }

            bool flag = true;
            for (int j = 0; j < 26; ++j)
            {
                if (flag && temp[j] < vec[j])
                {
                    flag = false;
                }
                temp[j] = 0;
            }

            if (flag)
                ans.push_back(words1[i]);
        }

        return ans;
    }
};