// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        vector<int> ans;
        vector<bool> st1(A.size()), st2(B.size());
        int cnt = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            if (st2[A[i]])
                ++cnt;
            if (st1[B[i]])
                ++cnt;

            if (A[i] == B[i])
                ++cnt;
            ans.push_back(cnt);
            st1[A[i]] = 1;
            st2[B[i]] = 1;
        }

        return ans;
    }
};