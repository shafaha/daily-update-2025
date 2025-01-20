// https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int r = mat.size(), c = mat[0].size();
        int sz = arr.size() + 1;
        vector<int> mpr(sz), mpc(sz), mpx(sz), mpy(sz);
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                mpr[mat[i][j]] = i;
                mpc[mat[i][j]] = j;
            }
        }

        for (int i = 0; i < arr.size(); ++i)
        {
            int x = mpr[arr[i]], y = mpc[arr[i]];
            ++mpx[x];
            ++mpy[y];

            if (mpx[x] == c)
                return i;
            if (mpy[y] == r)
                return i;
        }

        return -1;
    }
};