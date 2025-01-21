// https://leetcode.com/problems/merge-intervals/?envType=problem-list-v2&envId=sorting

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        vector<int> vec = intervals[0];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] > vec[1])
            {
                ans.push_back(vec);
                vec = intervals[i];
            }
            else
            {
                vec[0] = min(vec[0], intervals[i][0]);
                vec[1] = max(vec[1], intervals[i][1]);
            }
        }

        ans.push_back(vec);

        return ans;
    }
};