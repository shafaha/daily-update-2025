// https://leetcode.com/problems/number-of-matching-subsequences/description/?envType=problem-list-v2&envId=hash-table
// 792. Number of Matching Subsequences

class Solution
{
public:
    int findElementGreater(vector<int> &vec, int i)
    {
        if (vec.size() == 0)
            return -1;
        if (i > vec.back())
            return -1;
        int l = 0, r = vec.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (l == mid)
                break;
            if (i > vec[mid])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        // cout<<l<<" "<<r<<endl;
        if (vec[l] >= i)
            return vec[l];
        return vec[r];
    }
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<vector<int>> vec(26);
        for (int i = 0; i < s.size(); ++i)
        {
            vec[s[i] - 'a'].push_back(i);
        }

        int total = 0;
        for (const string &s : words)
        {
            int y = 0;
            bool flag = true;
            for (char c : s)
            {
                y = findElementGreater(vec[c - 'a'], y);
                // cout<<y<<" ";
                if (y < 0)
                {
                    flag = false;
                    break;
                }
                ++y;
            }
            // cout<<s<<endl;

            total += flag;
        }
        return total;
    }
};