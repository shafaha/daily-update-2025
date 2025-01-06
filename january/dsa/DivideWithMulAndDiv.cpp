// 29. Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/description/

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == -1 && dividend == -2147483648)
            return 2147483647;
        if (divisor == -1)
            return dividend * -1;
        if (divisor == 1)
            return dividend;
        if (divisor == -2147483648 && dividend == -2147483648)
            return 1;
        if (divisor == -2147483648)
            return 0;
        // I will use the shift operator to find out that
        int total = 0;
        int mul = 1;
        if (dividend < 0)
        {
            mul = -1;
            dividend += 1;
            dividend *= -1;
        }
        else
        {
            dividend -= 1;
        }

        if (divisor < 0)
        {
            mul *= -1;
            divisor *= -1;
        }

        while (dividend >= divisor)
        {
            long long y = divisor, x = 1;
            while (dividend >= y && x > 0 && y > 0)
            {
                y <<= 1;
                x <<= 1;
            }

            y >>= 1;
            x >>= 1;
            total += x;
            dividend -= y;
        }

        // cout<<dividend<<endl;
        total += (dividend + 1 == divisor);
        return total * mul;
    }
};