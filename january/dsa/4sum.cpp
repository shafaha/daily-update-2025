class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, long long target)
    {
        if (nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    // cout<<j<<" "<<nums[j]<<endl;
                    continue;
                }
                int l = j + 1, r = nums.size() - 1;
                while (l < r)
                {

                    long long sm = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                    if (sm == target)
                    {
                        // cout<<j<<endl;
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        --r;
                        while (l < r && nums[l] == nums[l - 1])
                            ++l;
                        while (l < r && nums[r] == nums[r + 1])
                            --r;
                    }
                    else if (sm > target)
                    {
                        --r;
                    }
                    else
                        ++l;
                }
            }
        }

        return ans;
    }
};