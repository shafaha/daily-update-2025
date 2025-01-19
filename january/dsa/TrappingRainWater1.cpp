// https://leetcode.com/problems/trapping-rain-water/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> vec(height.size());
        vec[0] = height[0];
        for (int i = 1; i < height.size(); ++i)
        {
            vec[i] = max(height[i], vec[i - 1]);
        }

        int right_max = height.back();
        int total = 0;
        for (int i = height.size() - 2; i >= 1; --i)
        {
            right_max = max(right_max, height[i]);
            total += (min(vec[i], right_max) - height[i]);
        }

        return total;
    }
};