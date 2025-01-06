// 1769. Minimum Number of Operations to Move All Balls to Each Box
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/submissions/1499713014/?envType=daily-question&envId=2025-01-06

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        vector<int> vec;
        int s = boxes[0] == '1';
        vec.push_back(0);
        for (int i = 1; i < boxes.size(); ++i)
        {
            vec.push_back(s + vec.back());
            s += boxes[i] == '1';
        }

        vector<int> ans(boxes.size());
        s = 0;
        int y = 0;
        for (int i = boxes.size() - 1; i >= 0; --i)
        {
            // cout<<vec[i]<< " ";
            ans[i] = vec[i] + y;
            s += boxes[i] - '0';
            y = s + y;
        }

        return ans;
    }
};