class Solution
{
public:
    int jump(vector<int> &nums)
    {
        // Minimum hops to the to the end
        vector<int> vec(nums.size());

        int mx = nums[0];
        int lst = 0;
        int cnt = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (lst < i)
            {
                ++cnt;
                lst = mx;
            }
            mx = max(mx, i + nums[i]);
        }

        return cnt;
    }
};