// https://leetcode.com/problems/ugly-number-ii/?envType=problem-list-v2&envId=heap-priority-queue

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;
        vector<long long> vec(n + 1);
        long long p2 = 0, p3 = 0, p5 = 0;
        long long nu2 = 2, nu3 = 3, nu5 = 5;
        vec[0] = 1;
        for (long long i = 1; i <= n; ++i)
        {
            long long nu = min({nu2, nu3, nu5});
            vec[i] = nu;

            if (nu == nu2)
            {
                p2++;
                nu2 = vec[p2] * 2;
            }

            if (nu == nu3)
            {
                p3++;
                nu3 = vec[p3] * 3;
            }

            if (nu == nu5)
            {
                p5++;
                nu5 = vec[p5] * 5;
            }
        }

        return vec[n - 1];
    }
};

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        unordered_set<long long> st;
        if (n == 1)
            return 1;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        q.push(1);
        int x = 0;
        long long y;

        for (int i = 1; i <= n; ++i)
        {
            y = q.top();
            q.pop();
            if (st.find(y * 2) == st.end())
            {
                q.push(y * 2);
                st.insert(y * 2);
            }

            if (st.find(y * 3) == st.end())
            {
                q.push(y * 3);
                st.insert(y * 3);
            }

            if (st.find(y * 5) == st.end())
            {
                q.push(y * 5);
                st.insert(y * 5);
            }
        }

        return y;
    }
};