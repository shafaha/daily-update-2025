// 33. Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=problem-list-v2&envId=binary-search

class Solution
{
public:
    int findTarget(vector<int> &vec, int l, int r, int target)
    {
        if (target < vec[l] || target > vec[r])
            return -1;

        while (l < r)
        {
            int mid = (l + r) / 2;
            if (l == mid)
                break;

            if (target < vec[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }

        if (vec[l] == target)
            return l;
        if (vec[r] == target)
            return r;
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        // Find the inflexion point then search for the shit
        if (nums.size() == 1)
            return nums.back() == target ? 0 : -1;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (l == mid)
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

        int inf;
        if (nums[l] < nums[r])
        {
            inf = l;
        }
        else
        {
            inf = r;
        }

        // cout<<inf;
        if (target >= nums[0] && inf > 0)
            return findTarget(nums, 0, inf - 1, target);
        return findTarget(nums, inf, nums.size() - 1, target);
    }
};