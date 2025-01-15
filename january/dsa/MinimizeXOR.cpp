// https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = 0;
        while (num2) {
            num2 -= (num2 & -num2);
            ++x;
        }

        int y = (1 << 30);
        int ans = 0;
        for (int i = 0; i <= 30 && x > 0; ++i) {
            if (num1 & y) {
                --x;
                ans |= y;
            }
            y >>= 1;
        }

        // cout<<ans<<" "<<x<<endl;

        y = 1;
        while (x > 0) {
            if ((ans & y) == 0) {
                ans |= y;
                --x;
            }
            y <<= 1;
        }

        return ans;
    }
};