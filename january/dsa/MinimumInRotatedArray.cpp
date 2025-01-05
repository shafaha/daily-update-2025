

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int mid = (l + r) / 2;
            if (mid == l)
                break;
            if (nums[mid] > nums.back())
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        if (nums[l] < nums[r])
            return nums[l];
        return nums[r];
    }
};